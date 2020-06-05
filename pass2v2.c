#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    int i = 1,j = 1,k = 1,l = 1;
    int e = 0x0000;
    FILE *f1,*f2,*f3,*f4,*f5;
    f1 = fopen("intermediate_table.txt","r");
    f2 = fopen("optab.txt","r");
    f3 = fopen("symbol_table.txt","r");
    f4 = fopen("ObjectCode.txt","w");
    f5 = fopen("ObjectCodeRefer.txt","w");
    char address[100][100];
    char label[100][100];
    char opcode[100][100];
    char operand[100][100];
    char *t, *u, *v;
    char str1[100], str2[100];
    int length;
    int add1,add2;
    char opName[100][100];
    char opVal[100][100];
    char symName[100][100];
    char symAdd[100][100];
    int opCount1 = 0,opCount2 = 0;
    int symCount1 = 0,symCount2 = 0;
    fgets(str1,30,f1);
    t = strtok(str1," \t");
    int addArr[50];
    int a;

    while(t != NULL)
    {
        c++;
        //printf("%s\n",t);
        if(c == 1)
        {
            strcpy(address[0],t);
            printf("%s\t",address[0]);
        }
        if(c == 2)
        {
            strcpy(label[0],t);
            printf("%s\t",label[0]);
        }
        if(c == 3)
        {
            strcpy(opcode[0],t);
            printf("%s\t",opcode[0]);
        }
        if(c == 4)
        {
            strcpy(operand[0],t);
            printf("%s\n",operand[0]);
        }
        t = strtok(NULL," \t");
    }

    c = 0;
    //printf("\n%s",opcode[0]);
    if(strcmp(opcode[0],"START") == 0)
    {
        printf("\nEntering If\n");
        while(!feof(f1))
        {
            fgets(str1,32,f1);
            t = strtok(str1," \t");
            //printf("Enter If");
            while(t != NULL)
            {
                c++;
                if(c == 1)
                {
                    strcpy(address[i],t);
                    printf("%s\t",address[i]);
                    i++;
                }
                if(c == 2)
                {
                    strcpy(label[j],t);
                    printf("%s\t",label[j]);
                    j++;
                }
                if(c == 3)
                {
                    strcpy(opcode[k],t);
                    printf("%s\t",opcode[k]);
                    k++;
                }
                if(c == 4)
                {
                    strcpy(operand[l],t);
                    printf("%s\n",operand[l]);
                    l++;
                }
                t = strtok(NULL," \t");
            }
            c = 0;
        }

        sscanf(address[l-1],"%x",&add1);
        sscanf(address[1],"%x",&add2);

        for(a = 0;a < l;a++)
        {
            sscanf(address[a],"%x",&addArr[a]);
        }

        printf("ADD1 = %x ADD2 = %x",addArr[l-1],addArr[1]);
        length = addArr[l-1] - addArr[1];
    //  printf("\nADD1 : %X - ADD2 : %X = Length : %X",address[l-2],address[1],length);
        fprintf(f4,"\nH^%s^%X^%X",label[0],addArr[1],length);


    }

    printf("\nEntering OPTAB\n");

    while(!feof(f2))
    {
        fgets(str1,32,f2);
        u = strtok(str1, " \t");
        while(u != NULL)
        {
            if(c == 0)
            {
                strcpy(opName[opCount1],u);
                printf("%s\t",opName[opCount1]);
                opCount1++;
            }
            if(c == 1)
            {
                strcpy(opVal[opCount2],u);
                printf("%s\t",opVal[opCount2]);
                opCount2++;
            }

            u = strtok(NULL," \t");
            c++;
        }
        c = 0;
    }
    printf("OPCOUNT1 = %d\n",opCount1);
    printf("Last Element : %s",opName[opCount1 - 3]);



}
