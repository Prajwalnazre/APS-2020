#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char line[100],linecopy[100],optabline[100],opcode[100],operand[100],label[100],operandname[100][100],*token;
    int count,SA,LOCCTR,i,j;
    _Bool flag=0,flag1=0;
    FILE *fp1,*fp2,*fp3,*fp4,*fp_op,*fp5;
    fp1=fopen("input.txt","r");
    fp2=fopen("inter.txt","w");
    fp3=fopen("sym_tab1.txt","w");
    fp4=fopen("optab.txt","r");
    fp5=fopen("length.txt","w");

    i=0;
    while(!feof(fp4))
    {
        fgets(optabline,100,fp4);
        token=strtok(optabline,"\t\n");
        count=0;
        while(token!=NULL)
        {
            if(count==0)
            {
                strcpy(operandname[i],token);
                i++;
            }
            token=strtok(NULL,"\t\n");
            count++;
        }
    }

    fgets(line,100,fp1);
    strcpy(linecopy,line);
    count=0;
    token=strtok(line,"\t\n");
    while(token!=NULL)
    {
        if(count==1 && strcmp(token,"START ")==0)
        {
            flag=1;
        }
        if(count==2 && flag)
        {
            printf("Start Found\n");
            SA=(int)strtol(token,NULL,16);
        }
        token=strtok(NULL,"\t\n");
        count++;
    }
    LOCCTR=SA;
    fprintf(fp2,"%X\t%s",LOCCTR,linecopy);
    while(!feof(fp1))
    {
        count=0;
        fgets(line,100,fp1);
        strcpy(linecopy,line);
        fprintf(fp2,"%X\t%s",LOCCTR,line);
        token=strtok(line,"\t\n");
        while(token!=NULL)
        {
            token=strtok(NULL,"\t\n");
            count++;
        }
        if(count==2)
        {
            count=0;
            token=strtok(linecopy,"\t\n");
            while(token!=NULL)
            {
                if(count==0)
                    strcpy(opcode,token);
                if(count==1)
                    strcpy(operand,token);
                token=strtok(NULL,"\t\n");
                count++;
            }
        }
        else if(count==3)
        {
            count=0;
            token=strtok(linecopy,"\t\n");
            while(token!=NULL)
            {
                if(count==0)
                    strcpy(label,token);
                if(count==1)
                    strcpy(opcode,token);
                if(count==2)
                    strcpy(operand,token);
                token=strtok(NULL,"\t\n");
                count++;
            }
            fprintf(fp3,"%X\t%s\n",LOCCTR,label);
        }

        if(strcmp(opcode,"WORD")==0)
            LOCCTR+=3;
        else if(strcmp(opcode,"RESW")==0)
            LOCCTR+=3*atoi(operand);
        else if(strcmp(opcode,"RESB")==0)
            LOCCTR+=atoi(operand);
        else if(strcmp(opcode,"BYTE")==0)
        {
            if(operand[0]=='C')
            {
                LOCCTR+=(strlen(operand)-3);
            }
            else if(operand[0]=='X')
            {
                LOCCTR+=(strlen(operand)-3)/2;
            }
        }
        else
        {
            LOCCTR+=3;
            for(j=0;j<i;j++)
                if(strcmp(opcode,operandname[j])==0)
                    flag1=1;
            if(flag1==0)
                printf("Error\t%s\n",opcode);
            flag1=0;
        }

    }
    fprintf(fp5,"%X",LOCCTR-SA);
}
