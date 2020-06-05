#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUS 1
#define SHARP 2
#define AT 3

#define BUFFER_SIZE 256
#define LABEL_LENGTH 32
#define SYMTAB_SIZE 20
#define IMR_SIZE 100
#define RLD_SIZE 20
#define EXT_SIZE 20
#define ESD_SIZE 20
#define CSECT_SIZE 10

typedef struct OperationCodeTable {
	char Mnemonic[LABEL_LENGTH];
	char Format;
	unsigned short int  ManchineCode;
}SIC_OPTAB;

typedef struct SymbolTable {
	char Label[LABEL_LENGTH];
	int Address;
}SIC_SYMTAB;

typedef struct EXTREF {
	char Label[LABEL_LENGTH];
} EXTREF;

typedef struct EXTDEF {
	char Label[LABEL_LENGTH];
	int Address;
} EXTDEF;

typedef struct RegisterTable {
	char name[LABEL_LENGTH];
	int id;
} SIC_XE_REGISTER;

typedef struct RelocationDictionary {
	int Address;
	int Nibbles;
} RLD;

typedef struct ExternalSymbolDictionary {
	char Label[LABEL_LENGTH];
	char sign;
	int Address;
	int Nibbles;
} ESD;

typedef struct IntermediateRecord {
	unsigned short int LineIndex;
	unsigned short int Loc;
	unsigned long long int ObjectCode;
	char LabelField[LABEL_LENGTH];
	char OperatorField[LABEL_LENGTH];
	char OperandField[LABEL_LENGTH];
}IntermediateRec;

int len,l;
int Counter;
int RegIdx;
int SymIdx;
int ExtRefIdx;
int LOCCTR[IMR_SIZE];
int LocctrCounter = 0;
int Flag;
int Index;
int i,j,x,k;
int ManchineCode;
int SymtabCounter[CSECT_SIZE] = { 0, };
int start_address[CSECT_SIZE] = { 0, };
int program_length[CSECT_SIZE] = { 0, };
int ArrayIndex[CSECT_SIZE] = { 0, };
int RLDCounter[CSECT_SIZE] = { 0, };
int ExtRefCounter[CSECT_SIZE] = { 0, };
int ExtDefCounter[CSECT_SIZE] = { 0, };
int ESDCounter[CSECT_SIZE] = { 0, };
int CSectCounter = 0;
char End_operand[LABEL_LENGTH];

unsigned short int FoundOnSymtab_flag = 0;
unsigned short int FoundOnOptab_flag = 0;
unsigned short int FoundOnRegTab_flag = 0;
unsigned short int FoundOnExtRefTab_flag = 0;

char Buffer[BUFFER_SIZE];
char Label[LABEL_LENGTH];
char Mnemonic[LABEL_LENGTH];
char Operand[LABEL_LENGTH];

SIC_SYMTAB SYMTAB[CSECT_SIZE][SYMTAB_SIZE];
EXTREF ExtRefTAB[CSECT_SIZE][EXT_SIZE];
EXTDEF ExtDefTAB[CSECT_SIZE][EXT_SIZE];
IntermediateRec* IMRArray[CSECT_SIZE][IMR_SIZE];
RLD RLDArray[CSECT_SIZE][RLD_SIZE];
ESD ESDArray[CSECT_SIZE][ESD_SIZE];

static SIC_XE_REGISTER REG_TAB[] =
{
	{ "A", 0 },{ "X", 1 },{ "L", 2 },{ "B", 3 },{ "S", 4 },{ "T", 5 },{ "F", 6 },{ "PC", 8 },{ "SW", 9 }
};

static SIC_OPTAB OPTAB[] =
{
	{ "ADDF", '3', 0x58 },{ "COMPF", '3', 0x88 },{ "DIVF", '3', 0x64 },{ "FIX", '1', 0xC4 },{ "FLOAT", '1', 0xC0 },{ "LDF", '3', 0x70 },{ "MULF", '3', 0x60 },{ "NORM", '1', 0xC8 },
	{ "STF", '3', 0x80 },{ "SUBF", '3', 0x5C },{ "ADDR", '2', 0x90 },{ "CLEAR", '2', 0xB4 },{ "COMPR", '2', 0xA0 },{ "DIVR", '2', 0x9C },{ "HIO", '1', 0xF4 },{ "LDB", '3', 0x68 },
	{ "LDS", '3', 0x6C },{ "LDT" , '3', 0x74 },{ "LPS", '3', 0xD0 },{ "MULR", '2', 0x98 },{ "RMO", '2', 0xAC },{ "SHIFTL", '2', 0xA4 },{ "SHIFTR", '2', 0xA8 },{ "SIO", '1', 0xF0 },
	{ "SSK", '3', 0xEC },{ "STB", '3', 0x78 },{ "STS", '3', 0x7C },{ "STT", '3', 0x84 },{ "SUBR", '2', 0x94 },{ "SVC", '2', 0xB0 },{ "TIO", '1', 0xF8 },{ "TIXR", '2', 0xB8 },
	{ "ADD",  '3',  0x18 },{ "AND",  '3',  0x40 },{ "COMP",  '3',  0x28 },{ "DIV",  '3',  0x24 },{ "J",  '3',  0x3C },{ "JEQ",  '3',  0x30 },{ "JGT",  '3',  0x34 },{ "JLT",  '3',  0x38 },
	{ "JSUB",  '3',  0x48 },{ "LDA",  '3',  0x00 },{ "LDCH",  '3',  0x50 },{ "LDL",  '3',  0x08 },{ "LDX",  '3',  0x04 },{ "MUL",  '3',  0x20 },{ "OR",  '3',  0x44 },
	{ "RD",  '3',  0xD8 },{ "RSUB",  '3',  0x4F },{ "STA",  '3',  0x0C },{ "STCH",  '3',  0x54 },{ "STL",  '3',  0x14 },{ "STSW",  '3',  0xE8 },{ "STX",  '3',  0x10 },
	{ "SUB",  '3',  0x1C },{ "TD",  '3',  0xE0 },{ "TIX",  '3',  0x2C },{ "WD",  '3',  0xDC },
};

char* ReadLabel() {
	j = 0;
	while (Buffer[Index] != ' ' && Buffer[Index] != '\t' && Buffer[Index] != '\n')
		Label[j++] = Buffer[Index++];
	Label[j] = '\0';
	return(Label);
}

void SkipSpace() {
	while (Buffer[Index] == ' ' || Buffer[Index] == '\t')
		Index++;
}

int ReadFlag(char *Mnemonic) {
	Flag = 0;
	switch (Mnemonic[0]) {
	case '+':
		Flag = PLUS;
		break;
	case '#':
		Flag = SHARP;
		break;
	case '@':
		Flag = AT;
		break;
	default:
		Flag = 0;
	}
	return Flag;
}

char* ReadOprator() {
	j = 0;
	while (Buffer[Index] != ' ' && Buffer[Index] != '\t' && Buffer[Index] != '\n')
		Mnemonic[j++] = Buffer[Index++];
	Mnemonic[j] = '\0';
	return(Mnemonic);
}

char* ReadOperand() {
	j = 0;
	while (Buffer[Index] != ' ' && Buffer[Index] != '\t' && Buffer[Index] != '\n')
		Operand[j++] = Buffer[Index++];
	Operand[j] = '\0';
	return(Operand);
}

void RecordSymtab(char* label) {
	if (ReadFlag(label)) {
		label = label + 1;
	}
	strcpy(SYMTAB[CSectCounter][SymtabCounter[CSectCounter]].Label, label);
	SYMTAB[CSectCounter][SymtabCounter[CSectCounter]].Address = LOCCTR[LocctrCounter - 1];
	SymtabCounter[CSectCounter]++;
}

void RecordRLD(char* Mnemonic, int loc, int idx) {
	RLDArray[idx][RLDCounter[idx]].Address = loc + 1;
	RLDArray[idx][RLDCounter[idx]].Nibbles = 3;
	if (ReadFlag(Mnemonic)) {
		RLDArray[idx][RLDCounter[idx]].Nibbles += 2;
	}
	RLDCounter[idx]++;
}

void RecordESD(char * Mnemonic, int loc, int byte, int idx) {
	ESDArray[idx][ESDCounter[idx]].Address = loc + 1;
	ESDArray[idx][ESDCounter[idx]].sign = '+';
	if (Mnemonic[0] == '-') {
		ESDArray[idx][ESDCounter[idx]].sign = '-';
		Mnemonic += 1;
	} else if (Mnemonic[0] == '+') {
		Mnemonic += 1;
	}
	ESDArray[idx][ESDCounter[idx]].Nibbles = 3;
	if (byte == 4) {
		ESDArray[idx][ESDCounter[idx]].Nibbles += 2;
	}
	strcpy(ESDArray[idx][ESDCounter[idx]].Label, Mnemonic);
	ESDCounter[idx]++;
}

void RecordEXTREF(char * Mnemonic) {
	strcpy(ExtRefTAB[CSectCounter][ExtRefCounter[CSectCounter]].Label, Mnemonic);
	ExtRefCounter[CSectCounter]++;
}

void RecordEXTDEF(char * Mnemonic) {
	strcpy(ExtDefTAB[CSectCounter][ExtDefCounter[CSectCounter]].Label, Mnemonic);
	ExtDefCounter[CSectCounter]++;
}

int RecordEXTDEFLoc() {
	int i;
	for (i = 0; i < ExtDefCounter[CSectCounter]; i++) {
		if (SearchSymtab(ExtDefTAB[CSectCounter][i].Label, CSectCounter)) {
			ExtDefTAB[CSectCounter][i].Address = SYMTAB[CSectCounter][SymIdx].Address;
		} else {
			return 1;
		}
	}
	return 0;
}

int SearchSymtab(char* label, int idx) {
	FoundOnSymtab_flag = 0;
	if (ReadFlag(label)) {
		label = label + 1;
	}

	for ( k = 0; k <= SymtabCounter[idx]; k++) {
		if (!strcmp(SYMTAB[idx][k].Label, label)) {
			FoundOnSymtab_flag = 1;
			SymIdx = k;
			return (FoundOnSymtab_flag);
		}
	}
	return (FoundOnSymtab_flag);
}

int SearchOptab(char * Mnemonic) {
	int size = sizeof(OPTAB) / sizeof(SIC_OPTAB);
	FoundOnOptab_flag = 0;
	if (ReadFlag(Mnemonic)) {
		Mnemonic = Mnemonic + 1;
	}
	for ( i = 0; i<size; i++) {
		if (!strcmp(Mnemonic, OPTAB[i].Mnemonic)) {
			Counter = i;
			FoundOnOptab_flag = 1;
			break;
		}
	}
	return (FoundOnOptab_flag);
}

int SearchRegTab(char * Mnemonic) {
	int size = sizeof(REG_TAB) / sizeof(SIC_XE_REGISTER);
	FoundOnRegTab_flag = 0;
	for ( i = 0; i < size; i++) {
		if (!strcmp(Mnemonic, REG_TAB[i].name)) {
			RegIdx = i;
			FoundOnRegTab_flag = 1;
			break;
		}
	}
	return (FoundOnRegTab_flag);
}

int SearchExtRefTAB(char * Mnemonic, int idx) {
	if (ReadFlag(Mnemonic)) {
		Mnemonic += 1;
	}
	FoundOnExtRefTab_flag = 0;
	for ( i = 0; i < ExtRefCounter[idx]; i++) {
		if (!strcmp(Mnemonic, ExtRefTAB[idx][i].Label)) {
			ExtRefIdx = i;
			FoundOnExtRefTab_flag = 1;
			break;
		}
	}
	return (FoundOnExtRefTab_flag);
}

int isNum(char * str) {
	if (ReadFlag(str)) {
		str += 1;
	}
	int i, len = strlen(str);
	for (i = 0; i < len; ++i) {
		if ('0' > str[i] || '9' < str[i]) {
			if (str[i] == '-') continue;
			return 0;
		}
	}
	return 1;
}

int isFloatNum(char * str) {
	if (ReadFlag(str)) {
		str += 1;
	}
	int i, len = strlen(str), f = 0;
	for (i = 0; i < len; ++i) {
		if ('0' > str[i] || '9' < str[i]) {
			if (str[i] == '.' && f == 0) {
				f = 1;
				continue;
			}
			if (str[i] == '-') continue;
			return 0;
		}
	}
	return (f != 0) ? 1 : 0;
}

unsigned long ConvertNumber(int diff, int nibble) {
	if (diff >= 0) {
		return diff;
	}
	if (nibble == 5) {
		diff ^= 0xFFF00000;
	} else {
		diff ^= 0xFFFFF000;
	}
	return diff;
}

int StrToDec(char* c) {
	if (ReadFlag(c)) {
		c += 1;
	}
	int dec_num = 0;
	char temp[10];
	strcpy(temp, c);

	 len = strlen(c);
	for ( k = len - 1, l = 1; k >= 0; k--)
	{
		if (temp[0] == '-') {
			continue;
		}
		dec_num = dec_num + (int)(temp[k] - '0')*l;
		l = l * 10;
	}
	return (temp[0] == '-') ? (-dec_num) : (dec_num);
}

int StrToHex(char* c)
{
	int hex_num = 0;
	char temp[10];
	strcpy(temp, c);

	len = strlen(temp);
	for ( k = len - 1, l = 1; k >= 0; k--)
	{
		if (temp[k] >= '0' && temp[k] <= '9')
			hex_num = hex_num + (int)(temp[k] - '0')*l;
		else if (temp[k] >= 'A' && temp[k] <= 'F')
			hex_num = hex_num + (int)(temp[k] - 'A' + 10)*l;
		else if (temp[k] >= 'a' && temp[k] >= 'f')
			hex_num = hex_num + (int)(temp[k] - 'a' + 10)*l;
		else;
		l = l * 16;
	}
	return (hex_num);
}

double StrToFloat(char* c) {
	double float_num = 0;
	len = strlen(c);
	for ( i = len - 1; i >= 0; i--) {
		float_num /= 10.0;
		float_num += (c[i] - '0')/10.0;
	}
	return float_num;
}

unsigned long long ConvertFloatNum(char * operand) {
	int dec_size = 0, b = 0, k = 0;
	int i = 0, j = 0;
	unsigned long long int s = 0, dec = 0, f = 0, e = 0x400;
	double frac = 0;
	char temp[1000];

	if (ReadFlag(operand)) {
		operand += 1;
	}
	if (operand[0] == '-') {
		s = 1;
		operand += 1;
	}
	do {
		if (operand[i] == '.') {
			temp[j] = '\0';
			dec = StrToDec(temp);
			if (dec > 0) {
				dec_size = log2(dec) + 1;
			}
			j = 0;
		}
		else if (operand[i] == '\0') {
			temp[j] = '\0';
			frac = StrToFloat(temp);
			if ((dec + frac) == 0) {
				return 0;
			}
			while (frac == 0 || 36 - dec_size > b) {
				frac *= 2;
				f <<= 1;
				if (f != 0 || dec_size != 0) {
					b++;
				}

				if ((int)frac >= 1) {
					frac -= 1;
					f += 1;
				} else if (f == 0) {
					k += 1;
				}
			}
		}
		else {
			temp[j++] = operand[i];
		}
	} while (operand[i++] != '\0');

	e += (dec_size > 0) ? (dec_size - 1) : (-k);

	if (dec_size > 36) {
		dec >>= (dec_size - 36);
		dec_size = 36;
	}
	else {
		dec <<= (36 - dec_size);
	}

	if (b >= (36 - dec_size)) {
		f >>= (b - (36 - dec_size));
	}
	else {
		f <<= ((36 - dec_size) - b);
	}
	return (s << 47) + (e << 36) + dec + f;
}

int ComputeLen(char* c) {
	unsigned int b;
	char len[32];

	strcpy(len, c);
	if (len[0] == 'C' || len[0] == 'c' && len[1] == '\'') {
		for (b = 2; b <= strlen(len); b++) {
			if (len[b] == '\'') {
				b -= 2;
				break;
			}
		}
	}
	if (len[0] == 'X' || len[0] == 'x' && len[1] == '\'')
		b = 1;
	return (b);
}

void CreateSymbolTable() {
	int loop, csect_loop;
	FILE *fptr_sym;
	fptr_sym = fopen("symtab.list", "w");

	if (fptr_sym == NULL)
	{
		printf("ERROR: Unable to open the symtab.list.\n");
		exit(1);
	}

	for (csect_loop = 0; csect_loop <= CSectCounter; csect_loop++) {
		printf("%-10s\t%-4s\n", "LABEL", "LOC");
		fprintf(fptr_sym, "%-10s\t%-4s\n", "LABEL", "LOC");
		for (loop = 0; loop < SymtabCounter[csect_loop]; loop++) {
			printf("%-10s\t%04X\n", SYMTAB[csect_loop][loop].Label, SYMTAB[csect_loop][loop].Address);
			fprintf(fptr_sym, "%-10s\t%04X\n", SYMTAB[csect_loop][loop].Label, SYMTAB[csect_loop][loop].Address);
		}
		printf("\n");
		fprintf(fptr_sym, "\n");
	}
	fclose(fptr_sym);
}

void CreateProgramList() {
	int loop, csect_loop;
	int len;
	FILE *fptr_list;

	fptr_list = fopen("sic.list", "w");

	if (fptr_list == NULL)
	{
		printf("ERROR: Unable to open the sic.list.\n");
		exit(1);
	}

	for (csect_loop = 0; csect_loop <= CSectCounter; csect_loop++) {
		fprintf(fptr_list, "%-4s\t%-10s%-10s%-10s\t%s\n", "LOC", "LABEL", "OPERATOR", "OPERAND", "OBJECT CODE");
		for (loop = 0; loop < ArrayIndex[csect_loop]; loop++)
		{
			len = 0;
			if (strlen(IMRArray[csect_loop][loop]->OperandField) <= 0
				&& !strcmp(IMRArray[csect_loop][loop]->OperatorField, "END")) {
				continue;
			}
			fprintf(fptr_list, "%04X\t%-10s%-10s%-10s\t",
				IMRArray[csect_loop][loop]->Loc,
				IMRArray[csect_loop][loop]->LabelField,
				IMRArray[csect_loop][loop]->OperatorField,
				IMRArray[csect_loop][loop]->OperandField);

			if (!strcmp(IMRArray[csect_loop][loop]->OperatorField, "START")
				|| !strcmp(IMRArray[csect_loop][loop]->OperatorField, "RESW")
				|| !strcmp(IMRArray[csect_loop][loop]->OperatorField, "RESB")
				|| !strcmp(IMRArray[csect_loop][loop]->OperatorField, "END")
				|| !strcmp(IMRArray[csect_loop][loop]->OperatorField, "BASE")
				|| !strcmp(IMRArray[csect_loop][loop]->OperatorField, "EXTREF")
				|| !strcmp(IMRArray[csect_loop][loop]->OperatorField, "EXTDEF"))
				fprintf(fptr_list, "\n");
			else if (SearchOptab(IMRArray[csect_loop][loop]->OperatorField)) {
				if (OPTAB[Counter].Format == '3') {
					if (ReadFlag(IMRArray[csect_loop][loop]->OperatorField)) {
						fprintf(fptr_list, "%08X\n", IMRArray[csect_loop][loop]->ObjectCode);
					}
					else {
						fprintf(fptr_list, "%06X\n", IMRArray[csect_loop][loop]->ObjectCode);
					}
				}
				else if (OPTAB[Counter].Format == '2') {
					fprintf(fptr_list, "%04X\n", IMRArray[csect_loop][loop]->ObjectCode);
				}
				else if (OPTAB[Counter].Format == '1') {
					fprintf(fptr_list, "%02X\n", IMRArray[csect_loop][loop]->ObjectCode);
				}
			}
			else {
				if (isFloatNum(IMRArray[csect_loop][loop]->OperandField)) {
					fprintf(fptr_list, "%012llX\n", IMRArray[csect_loop][loop]->ObjectCode);
				}
				else {
					len = ComputeLen(IMRArray[csect_loop][loop]->OperandField);
					if (len == 1) {
						fprintf(fptr_list, "%02X\n", IMRArray[csect_loop][loop]->ObjectCode);
					}
					else if (len == 2) {
						fprintf(fptr_list, "%04X\n", IMRArray[csect_loop][loop]->ObjectCode);
					}
					else {
						fprintf(fptr_list, "%06X\n", IMRArray[csect_loop][loop]->ObjectCode);
					}
				}
			}
		}
		fprintf(fptr_list, "\n");
	}
	fclose(fptr_list);
}

void CreateObjectCode() {
	int first_address;
	int last_address;
	int temp_address;
	unsigned long long int temp_objectcode[30];
	int first_index;
	int last_index;
	int x, xx;
	int loop, csect_loop, len = 0;

	char temp_operator[12][10];
	char temp_operand[12][10];

	FILE *fptr_obj;
	fptr_obj = fopen("sic.obj", "w");
	if (fptr_obj == NULL)
	{
		printf("ERROR: Unable to open the sic.obj.\n");
		exit(1);
	}

	printf("Creating Object Code...\n\n");

	for (csect_loop = 0; csect_loop <= CSectCounter; csect_loop++) {
		loop = 0;
		if (!strcmp(IMRArray[csect_loop][loop]->OperatorField, "START") || !strcmp(IMRArray[csect_loop][loop]->OperatorField, "CSECT"))
		{
			printf("H%-6s%06X%06X\n", IMRArray[csect_loop][loop]->LabelField, start_address[csect_loop], program_length[csect_loop]);
			fprintf(fptr_obj, "H^%-6s^%06X^%06X\n", IMRArray[csect_loop][loop]->LabelField, start_address[csect_loop], program_length[csect_loop]);
			loop++;
		}

		if (ExtDefCounter[csect_loop] > 0) {
			printf("D");
			fprintf(fptr_obj, "D");
			for (x = 0; x < ExtDefCounter[csect_loop]; x++) {
				printf("%-6s%06X", ExtDefTAB[csect_loop][x].Label, ExtDefTAB[csect_loop][x].Address);
				fprintf(fptr_obj, "^%-6s^%06X", ExtDefTAB[csect_loop][x].Label, ExtDefTAB[csect_loop][x].Address);
			}
			printf("\n");
			fprintf(fptr_obj, "\n");
		}

		if (ExtRefCounter[csect_loop] > 0) {
			printf("R");
			fprintf(fptr_obj, "R");
			for (x = 0; x < ExtRefCounter[csect_loop]; x++) {
				printf("%-6s", ExtRefTAB[csect_loop][x].Label);
				fprintf(fptr_obj, "^%-6s", ExtRefTAB[csect_loop][x].Label);
			}
			printf("\n");
			fprintf(fptr_obj, "\n");
		}

		while (1)
		{
			first_address = IMRArray[csect_loop][loop]->Loc;
			last_address = IMRArray[csect_loop][loop]->Loc + 29;
			first_index = loop;
			for (x = 0, temp_address = first_address; temp_address <= last_address; loop++) {
            if (!strcmp(IMRArray[csect_loop][loop]->OperatorField, "END")) {

					break;
				} else if (strcmp(IMRArray[csect_loop][loop]->OperatorField, "RESB")
					&& strcmp(IMRArray[csect_loop][loop]->OperatorField, "RESW")
					&& strcmp(IMRArray[csect_loop][loop]->OperatorField, "BASE")
					&& strcmp(IMRArray[csect_loop][loop]->OperatorField, "NOBASE")
					&& strcmp(IMRArray[csect_loop][loop]->OperatorField, "EXTREF")
					&& strcmp(IMRArray[csect_loop][loop]->OperatorField, "EXTDEF")) {
					temp_objectcode[x] = IMRArray[csect_loop][loop]->ObjectCode;
					strcpy(temp_operator[x], IMRArray[csect_loop][loop]->OperatorField);
					strcpy(temp_operand[x], IMRArray[csect_loop][loop]->OperandField);
					last_index = loop + 1;
					x++;
				}
				temp_address = IMRArray[csect_loop][loop + 1]->Loc;
				if (SearchOptab(IMRArray[csect_loop][loop + 1]->OperatorField)) {
					if (ReadFlag(IMRArray[csect_loop][loop + 1]->OperatorField)) {
						temp_address += 1;
					}
					temp_address += OPTAB[Counter].Format - '0';
				}
				else {
					if (!strcmp(IMRArray[csect_loop][loop + 1]->OperatorField, "WORD")
						|| !strcmp(IMRArray[csect_loop][loop + 1]->OperatorField, "BYTE")) {
						if (isFloatNum(IMRArray[csect_loop][loop + 1]->OperandField)) {
							temp_address += 6;
						}
						else if (!strcmp(IMRArray[csect_loop][loop + 1]->OperatorField, "BYTE")) {
							temp_address += ComputeLen(IMRArray[csect_loop][loop + 1]->OperandField);
						}
						else if (!strcmp(IMRArray[csect_loop][loop + 1]->OperatorField, "WORD")) {
							temp_address += 3;
						}
					}
				}
			}

			if ((IMRArray[csect_loop][last_index]->Loc - IMRArray[csect_loop][first_index]->Loc) == 0) {
				if (!strcmp(IMRArray[csect_loop][loop]->OperatorField, "END"))
					break;
				else
					continue;
			}
			printf("T%06X%02X", first_address, (IMRArray[csect_loop][last_index]->Loc - IMRArray[csect_loop][first_index]->Loc));
			fprintf(fptr_obj, "T^%06X^%02X", first_address, (IMRArray[csect_loop][last_index]->Loc - IMRArray[csect_loop][first_index]->Loc));

			for (xx = 0; xx < x; xx++) {
				if ((strcmp(temp_operator[xx], "BYTE") == 0)) {
					if (temp_operand[xx][0] == 'X' || temp_operand[xx][0] == 'x') {
						printf("%02X", temp_objectcode[xx]);
						fprintf(fptr_obj, "^%02X", temp_objectcode[xx]);
					}
					else if (isFloatNum(temp_operand[xx])) {
						printf("%012llX", temp_objectcode[xx]);
						fprintf(fptr_obj, "^%012llX", temp_objectcode[xx]);
					}
					else {
						printf("%06X", temp_objectcode[xx]);
						fprintf(fptr_obj, "^%06X", temp_objectcode[xx]);
					}
				}
				else {
					if (SearchOptab(temp_operator[xx])) {
						if (OPTAB[Counter].Format == '3') {
							if (ReadFlag(temp_operator[xx])) {
								printf("%08X", temp_objectcode[xx]);
								fprintf(fptr_obj, "^%08X", temp_objectcode[xx]);
							}
							else {
								printf("%06X", temp_objectcode[xx]);
								fprintf(fptr_obj, "^%06X", temp_objectcode[xx]);
							}
						}
						else if (OPTAB[Counter].Format == '2') {
							printf("%04X", temp_objectcode[xx]);
							fprintf(fptr_obj, "^%04X", temp_objectcode[xx]);
						}
						else if (OPTAB[Counter].Format == '1') {
							printf("%02X", temp_objectcode[xx]);
							fprintf(fptr_obj, "^%02X", temp_objectcode[xx]);
						}
					}
					else {
						if (isFloatNum(temp_operand[xx])) {
							printf("%012llX", temp_objectcode[xx]);
							fprintf(fptr_obj, "^%012llX", temp_objectcode[xx]);
						}
						else {
							printf("%06X", temp_objectcode[xx]);
							fprintf(fptr_obj, "^%06X", temp_objectcode[xx]);
						}
					}
				}
			}

			printf("\n");
			fprintf(fptr_obj, "\n");

			if (!strcmp(IMRArray[csect_loop][loop]->OperatorField, "END"))
				break;
		}
		for (loop = 0; loop < RLDCounter[csect_loop]; loop++) {
			printf("M%06X%02X\n", RLDArray[csect_loop][loop].Address, RLDArray[csect_loop][loop].Nibbles);
			fprintf(fptr_obj, "M^%06X^%02X\n", RLDArray[csect_loop][loop].Address, RLDArray[csect_loop][loop].Nibbles);
		}
		for (loop = 0; loop < ESDCounter[csect_loop]; loop++) {
			printf("M%06X%02X%c%s\n", ESDArray[csect_loop][loop].Address, ESDArray[csect_loop][loop].Nibbles, ESDArray[csect_loop][loop].sign, ESDArray[csect_loop][loop].Label);
			fprintf(fptr_obj, "M^%06X^%02X^%c%s\n", ESDArray[csect_loop][loop].Address, ESDArray[csect_loop][loop].Nibbles, ESDArray[csect_loop][loop].sign, ESDArray[csect_loop][loop].Label);
		}
		printf("E");
		fprintf(fptr_obj, "E");
		if (SearchSymtab(End_operand, csect_loop)) {
			printf("%06X\n\n", SYMTAB[csect_loop][SymIdx].Address);
			fprintf(fptr_obj, "^%06X\n\n", SYMTAB[csect_loop][SymIdx].Address);
		} else {
			printf("\n\n");
			fprintf(fptr_obj, "\n\n");
		}
	}
	fclose(fptr_obj);
}

void main(void)
{
	FILE* fptr;
	char filename[10];
	char label[32];
	char opcode[32];
	char operand[32];
	char tempLabel[LABEL_LENGTH];

	int loc = 0;
	int line = 0;
	int loop, csect_loop;
	int is_empty_line;
	int is_comment;
	int loader_flag = 0;
	int start_line = 0;
	int tempLabelIdx = 0;
	int i = 0;
	fptr = fopen("input.txt", "r");
	if (fptr == NULL)
	{
		printf("ERROR: Unable to open the %s file.\n", filename);
		exit(1);
	}

	printf("Pass 1 Processing...\n");
	while (fgets(Buffer, 256, fptr) != NULL)
	{
		is_empty_line = strlen(Buffer);

		Index = 0;
		j = 0;
		strcpy(label, ReadLabel());
		if (Label[0] == '.')
			is_comment = 1;
		else
			is_comment = 0;

		if (is_empty_line>1 && is_comment != 1)
		{
			Index = 0;
			j = 0;
			IMRArray[CSectCounter][ArrayIndex[CSectCounter]] = (IntermediateRec*)malloc(sizeof(IntermediateRec));
			IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->LineIndex = ArrayIndex;
			strcpy(label, ReadLabel());
			strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->LabelField, label);
			SkipSpace();

			if (line == start_line)
			{
				strcpy(opcode, ReadOprator());
				strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperatorField, opcode);
				if (!strcmp(opcode, "START")) {
					SkipSpace();
					strcpy(operand, ReadOperand());
					strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperandField, operand);
					LOCCTR[LocctrCounter] = StrToHex(operand);
					start_address[CSectCounter] = LOCCTR[LocctrCounter];
				} else {
					LOCCTR[LocctrCounter] = 0;
					start_address[CSectCounter] = LOCCTR[LocctrCounter];
				}
			} else {
				strcpy(opcode, ReadOprator());
				strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperatorField, opcode);
				SkipSpace();
				strcpy(operand, ReadOperand());
				strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperandField, operand);

				if (strcmp(opcode, "END"))
				{
					if (label[0] != '\0')
					{
						if (SearchSymtab(label, CSectCounter))
						{
							fclose(fptr);
							printf("ERROR: Duplicate Symbol\n");
							FoundOnSymtab_flag = 0;
							exit(1);
						}
						if (strcmp(opcode, "CSECT")) {
							RecordSymtab(label);
						}
					}

					if (SearchOptab(opcode)) {
						LOCCTR[LocctrCounter] = loc + (int)(OPTAB[Counter].Format - '0');
						if (ReadFlag(opcode)) {
							LOCCTR[LocctrCounter] += 1;
						}
					}
					else if (!strcmp(opcode, "WORD")) {
						if (isFloatNum(operand)) {
							LOCCTR[LocctrCounter] = loc + 6;
						} else {
							LOCCTR[LocctrCounter] = loc + 3;
						}
					} else if (!strcmp(opcode, "RESW"))
						LOCCTR[LocctrCounter] = loc + 3 * StrToDec(operand);
					else if (!strcmp(opcode, "RESB"))
						LOCCTR[LocctrCounter] = loc + StrToDec(operand);
					else if (!strcmp(opcode, "BYTE")) {
						if (isFloatNum(operand)) {
							LOCCTR[LocctrCounter] = loc + 6;
						} else {
							LOCCTR[LocctrCounter] = loc + ComputeLen(operand);
						}
					} else if (!strcmp(opcode, "BASE")
						|| !strcmp(opcode, "NOBASE")) {
						LOCCTR[LocctrCounter] = loc;
					}
					else if (!strcmp(opcode, "EXTDEF")
						|| !strcmp(opcode, "EXTREF")) {
						i = 0; tempLabelIdx = 0;
						while (1) {
							if (operand[i] == ',' || operand[i] == '\0') {
								tempLabel[tempLabelIdx] = '\0';
								if (!strcmp(opcode, "EXTDEF")) {
									RecordEXTDEF(tempLabel);
								}
								else if (!strcmp(opcode, "EXTREF")) {
									RecordEXTREF(tempLabel);
								}
								tempLabelIdx = 0;
								if (operand[i] == '\0') break;
							}
							else {
								tempLabel[tempLabelIdx++] = operand[i];
							}
							i++;
						}
						LOCCTR[LocctrCounter] = loc;
					}
					else if (!strcmp(opcode, "CSECT")) {
						if (RecordEXTDEFLoc()) {
							printf("ERROR: Isn't exist External Define Label\n");
							fclose(fptr);
							exit(1);
						}
						IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->LabelField[0] = '\0';
						IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->Loc = LOCCTR[LocctrCounter - 1];
						strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperatorField, "END");
						strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperandField, "");
						program_length[CSectCounter] = LOCCTR[LocctrCounter - 1] - LOCCTR[0];
						ArrayIndex[CSectCounter]++;
						CSectCounter++;
						line = 1;
						loc = 0;
						LocctrCounter = 0;
						LOCCTR[LocctrCounter] = 0;
						FoundOnOptab_flag = 0;

						IMRArray[CSectCounter][ArrayIndex[CSectCounter]] = (IntermediateRec *)malloc(sizeof(IntermediateRec));
						strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->LabelField, label);
						strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperandField, "");
						strcpy(IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->OperatorField, opcode);
						IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->LineIndex = 0;
						IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->Loc = 0;
						RecordSymtab(label);
						start_address[CSectCounter] = LOCCTR[LocctrCounter];
						LocctrCounter++;
						ArrayIndex[CSectCounter]++;
						continue;
					}
					else {
						fclose(fptr);
						printf("ERROR: Invalid Operation Code[%s]\n", opcode);
						exit(1);
					}
				}
				else {
					strcpy(End_operand, operand);
				}
			}
			loc = LOCCTR[LocctrCounter];
			IMRArray[CSectCounter][ArrayIndex[CSectCounter]]->Loc = LOCCTR[LocctrCounter - 1];
			LocctrCounter++;
			ArrayIndex[CSectCounter]++;
		}

		if (is_comment == 1) {
			start_line += 1;
		}

		FoundOnOptab_flag = 0;
		line += 1;
	}
	program_length[CSectCounter] = LOCCTR[LocctrCounter - 2] - LOCCTR[0];

	if (RecordEXTDEFLoc()) {
		printf("ERROR: Isn't exist External Define Label\n");
		fclose(fptr);
		exit(1);
	}
	CreateSymbolTable();

	printf("Pass 2 Processing...\n");

	unsigned long inst_fmt;
	unsigned long inst_fmt_opcode;
	unsigned long inst_fmt_sign;
	unsigned long inst_fmt_relative;
	unsigned long inst_fmt_index;
	unsigned long inst_fmt_extended;
	unsigned long inst_fmt_address;
	int inst_fmt_byte;
	int regCharIdx;
	char regName[3];

	int diff = 0;
	int base_register = -1;

	for (csect_loop = 0; csect_loop <= CSectCounter; csect_loop++) {
		base_register = -1;
		diff = 0;
		for (loop = 1; loop < ArrayIndex[csect_loop]; loop++) {
			inst_fmt_opcode = 0;
			inst_fmt_sign = 0;
			inst_fmt_relative = 0;
			inst_fmt_index = 0;
			inst_fmt_extended = 0;
			inst_fmt_address = 0;
			inst_fmt_byte = 0;
			regName[0] = '\0';
			tempLabel[0] = '\0';

			strcpy(opcode, IMRArray[csect_loop][loop]->OperatorField);

			if (SearchOptab(opcode)) {
				if (!strcmp(OPTAB[Counter].Mnemonic, "RSUB")) {
					IMRArray[csect_loop][loop]->ObjectCode = (OPTAB[Counter].ManchineCode << 16);
					continue;
				}
				inst_fmt_opcode = OPTAB[Counter].ManchineCode;
				inst_fmt_byte = OPTAB[Counter].Format - '0';
				if (inst_fmt_byte == 3 && ReadFlag(opcode)) {
					inst_fmt_byte = 4;
					inst_fmt_extended = 0x00100000;
				}
				inst_fmt_opcode <<= (8 * (inst_fmt_byte - 1));
				IMRArray[csect_loop][loop]->ObjectCode = inst_fmt_opcode;
				strcpy(operand, IMRArray[csect_loop][loop]->OperandField);

				if (ReadFlag(operand)) {
					if (inst_fmt_byte <= 2) {
						fclose(fptr);
						printf("ERROR: Invalid Addressing Mode\n");
						exit(1);
					}
					if (Flag == SHARP) {
						inst_fmt_sign = 0x010000;
					}
					else if (Flag == AT) {
						inst_fmt_sign = 0x020000;
					}
					inst_fmt_sign <<= 8 * (inst_fmt_byte - 3);
				}
				else if (inst_fmt_byte >= 3) {
					inst_fmt_sign = 0x030000;
					inst_fmt_sign <<= 8 * (inst_fmt_byte - 3);
				}

				if (inst_fmt_byte >= 3) {
					if (operand[strlen(operand) - 2] == ',' && operand[strlen(operand) - 1] == 'X') {
						inst_fmt_index = 0x008000;
						inst_fmt_index <<= 8 * (inst_fmt_byte - 3);
						operand[strlen(operand) - 2] = '\0';
					}

					if (SearchSymtab(operand, csect_loop)) {
						if (inst_fmt_byte == 4) {
							inst_fmt_address = SYMTAB[csect_loop][SymIdx].Address;
							RecordRLD(IMRArray[csect_loop][loop]->OperatorField, IMRArray[csect_loop][loop]->Loc, csect_loop);
						}
						else {
                                diff = SYMTAB[csect_loop][SymIdx].Address - IMRArray[csect_loop][loop]->Loc - inst_fmt_byte;
							if (diff >= -2048 && diff < 2048) {
								inst_fmt_address = 0x002000;
								inst_fmt_address += ConvertNumber(diff, 3);
							}
							else {
								diff = SYMTAB[csect_loop][SymIdx].Address - base_register;
								if (base_register != -1 && diff >= 0 && diff < 4096) {
									inst_fmt_address = 0x004000;
									inst_fmt_address += diff;
								}
								else {
									fclose(fptr);
									printf("ERROR: CANNOT present relative addressing mode[line : %d]\n", IMRArray[csect_loop][loop]->LineIndex);
									exit(1);
								}
							}
						}
					}
					else {
						ReadFlag(operand);
						if (Flag == SHARP && isNum(operand)) {
							inst_fmt_address = ConvertNumber(StrToDec(operand), (inst_fmt_byte == 4) ? 5 : 3);
						}
						else if (SearchExtRefTAB(operand, csect_loop)) {
							inst_fmt_address = 0;
							RecordESD(operand, IMRArray[csect_loop][loop]->Loc, inst_fmt_byte, csect_loop);
						}
						else {
							fclose(fptr);
							printf("ERROR: Label isn't exist [%s]\n", operand);
							exit(1);
						}
					}
				}
				else if (inst_fmt_byte == 2) {
					i = 0; regCharIdx = 0;
					do {
						if (operand[i] == ',' || operand[i] == '\0') {
							regName[regCharIdx] = '\0';
							if (operand[i] == ',') {
								inst_fmt_address <<= 4;
							}

							if (SearchRegTab(regName)) {
								inst_fmt_address += REG_TAB[RegIdx].id;
							}
							else {
								if (!strcmp(OPTAB[Counter].Mnemonic, "SVC")
									|| !strcmp(OPTAB[Counter].Mnemonic, "SHIFTL")
									|| !strcmp(OPTAB[Counter].Mnemonic, "SHIFTR")) {
									if (isNum(regName)) {
										inst_fmt_address += StrToDec(regName);
									}
								}
								else {
									fclose(fptr);
									printf("ERROR: Invalid Register\n");
									exit(1);
								}
							}
							regCharIdx = 0;
						}
						else if (operand[i] != ' ') {
							regName[regCharIdx++] = operand[i];
						}
					} while (operand[i++] != '\0');

					if (!strcmp(OPTAB[Counter].Mnemonic, "CLEAR")
						|| !strcmp(OPTAB[Counter].Mnemonic, "TIXR")
						|| !strcmp(OPTAB[Counter].Mnemonic, "SVC")) {
						inst_fmt_address <<= 4;
					}
				}

				inst_fmt = inst_fmt_opcode + inst_fmt_sign + inst_fmt_index + inst_fmt_relative + inst_fmt_extended + inst_fmt_address;
				IMRArray[csect_loop][loop]->ObjectCode = inst_fmt;
			}
			else if (!strcmp(opcode, "WORD")) {
				strcpy(operand, IMRArray[csect_loop][loop]->OperandField);
				if (isFloatNum(operand)) {
					IMRArray[csect_loop][loop]->ObjectCode = ConvertFloatNum(operand);
				}
				else {
					IMRArray[csect_loop][loop]->ObjectCode = StrToDec(operand);
				}
			}
			else if (!strcmp(opcode, "BYTE")) {
				strcpy(operand, IMRArray[csect_loop][loop]->OperandField);
				IMRArray[csect_loop][loop]->ObjectCode = 0;

				if (isFloatNum(operand)) {
					IMRArray[csect_loop][loop]->ObjectCode = ConvertFloatNum(operand);
				}
				else {
					if (operand[0] == 'C' || operand[0] == 'c' && operand[1] == '\'') {
						for ( x = 2; x <= (int)(strlen(operand) - 2); x++) {
							IMRArray[csect_loop][loop]->ObjectCode += (int)operand[x];
							IMRArray[csect_loop][loop]->ObjectCode <<= 8;
						}
					}

					if (operand[0] == 'X' || operand[0] == 'x' && operand[1] == '\'') {
						char *operand_ptr;
						operand_ptr = &operand[2];
						*(operand_ptr + 2) = '\0';
						for ( x = 2; x <= (int)(strlen(operand) - 2); x++) {
							IMRArray[csect_loop][loop]->ObjectCode += StrToHex(operand_ptr);
							IMRArray[csect_loop][loop]->ObjectCode <<= 8;
						}
					}

					IMRArray[csect_loop][loop]->ObjectCode >>= 8;
				}
			}
			else if (!strcmp(opcode, "BASE")) {
				strcpy(operand, IMRArray[csect_loop][loop]->OperandField);
				IMRArray[csect_loop][loop]->ObjectCode = 0;
				if (SearchSymtab(operand, csect_loop)) {
					base_register = SYMTAB[csect_loop][SymIdx].Address;
				}
				else {
					fclose(fptr);
					printf("ERROR: No Label in SYMTAB[%s]\n", operand);
					exit(1);
				}
			}
			else if (!strcmp(opcode, "NOBASE")) {
				IMRArray[csect_loop][loop]->ObjectCode = 0;
				base_register = -1;
			}
		}
	}

	CreateProgramList();
	CreateObjectCode();

	for (csect_loop = 0; csect_loop <= CSectCounter; csect_loop++) {
		for (loop = 0; loop < ArrayIndex[csect_loop]; loop++)
			free(IMRArray[csect_loop][loop]);
	}
	printf("Completed Assembly\n");
	fclose(fptr);

	exit(0);
}
