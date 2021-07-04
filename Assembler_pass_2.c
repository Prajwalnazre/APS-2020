#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    char labelarray[100][100],labeladdress[100][100],opcodename[100][100],opcodearray[100][100];
    char *token,*token1,line[100],linecopy[100],address[100],operand[100],label[100],opcode[100];
    char progname[100],startingadd[100],addressarray[100][100],newobjectcode[100][100],objectcodecopy[100];
    int count,x=0,y=0,length,count1,i,j,z=0,counter=0,a;
    fp1=fopen("sym_tab1.txt","r");
    fp2=fopen("optab.txt","r");
    fp3=fopen("inter.txt","r");
    fp4=fopen("length.txt","r");
    fp5=fopen("object_program.txt","w");

    while(!feof(fp1))
    {
        fgets(line,100,fp1);
        count=0;
        token=strtok(line,"\t\n");
        while(token!=NULL)
        {
            if(count==0)
                strcpy(labelarray[x],token);
            if(count==1)
            {
                strcpy(labeladdress[x],token);
                x++;
            }
            token=strtok(NULL,"\t\n");
            count++;
        }
    }

    while(!feof(fp2))
    {
        fgets(line,100,fp2);
        count=0;
        token=strtok(line,"\t\n");
        while(token!=NULL)
        {
            if(count==0)
                strcpy(opcodename[y],token);
            if(count==1)
            {
                strcpy(opcodearray[y],token);
                y++;
            }
            token=strtok(NULL,"\t\n");
            count++;
        }
    }

    fscanf(fp4,"%X",&length);

    fgets(line,100,fp3);
    strcpy(linecopy,line);
    count=0;
    token=strtok(line,"\t\n");
    while(token!=NULL)
    {
        if(count==2)
        {
            if(strcmp(token,"START ")==0)
            {
                count1=0;
                token1=strtok(linecopy,"\t\n");
                while(token1!=NULL)
                {
                    if(count1==1)
                        strcpy(progname,token1);
                    if(count1==3)
                        strcpy(startingadd,token1);
                    token1=strtok(NULL,"\n\t");
                    count1++;
                }
            }
        }
        token=strtok(NULL,"\n\t");
        count++;
    }
    printf("H^%s^%s^%X\n",progname,startingadd,length);
    printf("T");
    while(!feof(fp3))
    {
        fgets(line,100,fp3);
        strcpy(linecopy,line);
        count=0;
        token=strtok(line,"\t\n");
        while(token!=NULL)
        {
            token=strtok(NULL,"\t\n");
            count++;
        }
        if(count==3)
        {
            count=0;
            token=strtok(linecopy,"\t\n");
            while(token!=NULL)
            {
                if(count==0)
                    strcpy(address,token);
                if(count==1)
                    strcpy(opcode,token);
                if(count==2)
                    strcpy(operand,token);
                token=strtok(NULL,"\t\n");
                count++;
            }
        }
        else if(count==4)
        {
            count=0;
            token=strtok(linecopy,"\t\n");
            while(token!=NULL)
            {
                if(count==0)
                    strcpy(address,token);
                if(count==1)
                    strcpy(label,token);
                if(count==2)
                    strcpy(opcode,token);
                if(count==3)
                    strcpy(operand,token);
                token=strtok(NULL,"\t\n");
                count++;
            }
        }

        for(j=0;j<y;j++)
        {
            if(strcmp(opcode,opcodename[j])==0)
            {
                strcpy(newobjectcode[z],opcodearray[j]);
            }
        }

        if(counter>=60)
        {
            counter=0;
            printf("\nT");
        }

        for(i=0;i<x;i++)
        {
            if(strcmp(operand,labeladdress[i])==0)
            {
                strcat(newobjectcode[z],labelarray[i]);
                strcpy(objectcodecopy,newobjectcode[z]);
                counter+=strlen(objectcodecopy);
                printf("^%s",objectcodecopy);
                strcpy(addressarray[z],address);
                z++;
            }
        }
        if(strcmp(opcode,"WORD")==0)
        {
            printf("^%06X",atoi(operand));
            counter+=6;
        }
        if(strcmp(opcode,"BYTE")==0)
        {
            printf("^");
            if(operand[0]=='C')
            {
                a=1;
                while(operand[a]!='\0')
                {
                    if(operand[a]!='\'')
                    {
                        printf("%x",operand[a]);
                        counter=counter+1;
                    }
                    a++;
                }
            }
            else
            {
                a=1;
                while(operand[a]!='\0')
                {
                    if(operand[a]!='\'')
                    {
                        printf("%c",operand[a]);
                        counter=counter+2;
                    }
                    a++;
                }
            }
        }
    }
    printf("\nE^%s",startingadd);

}