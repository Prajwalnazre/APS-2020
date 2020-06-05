#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f1,*f2,*f3,*f4;
    int past,n1=0,found=0;
    int i,j,fg=0;
    f1=fopen("input.txt","r");
    f2=fopen("intermediate_table.txt","w");
    f3=fopen("optab.txt","r");
    char *t,*t1,*ptr,*ts;
    char first[100][50];
    char second[100][50];
    char third[100][50];
    char opcode[100][50];
    char duplicate[100][50];
    char last_opcode[100][50];
    char str1[100],str2[100],sym[100];
    int c=0;int c1,c2=0;
    int e=0x000;
    int flag=0;
    fgets(str1,30,f1);
    t=strtok(str1," \t");
    while(t!=NULL)
    {
        c++;
        printf("%s\n",t);
        if(c==1)
            strcpy(first[0],t);
        if(c==2)
            strcpy(second[0],t);
        if(c==3)
        {
            e=strtol(t,&ptr,16);
            printf("t=%x\n",e);
        }
        t=strtok(NULL," \t");
    }

    c=0;
    if((strcmp(second[0],"START")==0))
    {
    while(!feof(f1))
    {
        fgets(str1,30,f1);
        t=strtok(str1," \t");
        while(t!=NULL)
        {
            c++;
            if(c==1)
                strcpy(first[0],t);
            if(c==2)
                strcpy(second[0],t);
            if(c==3)
                strcpy(third[0],t);
            t=strtok(NULL," \t");
        }
        if(c==3)
        {
            while(!feof(f3))
            {
                fgets(str2,30,f3);
                t1=strtok(str2,"\t");
                while(t1!=NULL)
                {
                    c1++;
                    if(c1==1)
                        strcpy(opcode[0],t1);
                    t1=strtok(NULL,"\t");
                }
                if((strcmp(second[0],opcode[0]))==0)
                {
                    if(flag==0)
                    {
                        past=e;
                        fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                        e=e+3;
                        past=e;
                        flag=1;
                    }
                    else
                    {
                        fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                        e=e+3;
                        past=e;
                    }
                    break;
                }
                c1=0;
            }
            if((strcmp(second[0],"RESB"))==0)
            {
                   fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                   e=e+atoi(third[0]);
                   past=e;
            }
            else if((strcmp(second[0],"RESW"))==0)
            {
                    fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                    e=e+atoi(third[0]);
                    past=e;
            }
            else if((strcmp(second[0],"WORD"))==0)
            {
                    fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                    e=e+((strlen(third[0])-3)*3);
                    past=e;
            }
            else if((strcmp(second[0],"BYTE"))==0)
            {
                if(third[0][0]=='C')
                {
                    fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                    e=e+(strlen(third[0])-3);
                    past=e;
                }
                else
                {
                    fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                    e=e+((strlen(third[0])-3)/2);
                    past=e;
                }
            }
            else if((strcmp(second[0],"EQU"))==0)
            {
                fprintf(f2,"%x\t%s\t%s\t%s",past,first,second,third);
                e=e+3;
                past=e;
            }
            //else
              //  printf("opcode undefined");
         }
         c1=0;
         fclose(f3);
         //FILE *f3;
         f3=fopen("optab.txt","r");
         if(c==2)
         {
             while(!feof(f3))
            {
                fgets(str2,30,f3);
                t1=strtok(str2,"\t");
                while(t1!=NULL)
                {
                    c1++;
                    if(c1==1)
                        strcpy(opcode[0],t1);
                    t1=strtok(NULL,"\t");
                }
                if((strcmp(first[0],opcode[0]))==0)
                {
                    if(flag==0)
                    {
                        past=e;
                        fprintf(f2,"%x\t%s\t%s",past,first,second);
                        e=e+3;
                        past=e;
                        flag=1;
                    }
                    else
                    {
                        fprintf(f2,"%x\t%s\t%s",past,first,second);
                        e=e+3;
                        past=e;
                    }
                    break;
                }
                c1=0;
            }
         }
         c1=0;
         fclose(f3);
         //FILE *f3;
         f3=fopen("optab.txt","r");
         if(c==1)
         {
              while(!feof(f3))
            {
                fgets(str2,30,f3);
                t1=strtok(str2,"\t");
                while(t1!=NULL)
                {
                    c1++;
                    if(c1==1)
                        strcpy(opcode[0],t1);
                    t1=strtok(NULL,"\t");
                }
                if((strcmp(first[0],opcode[0]))==0)
                {
                    if(flag==0)
                    {
                        past=e;
                        fprintf(f2,"%x\t%s",past,first);
                        e=e+3;
                        past=e;
                        flag=1;
                    }
                    else
                    {
                        fprintf(f2,"%x\t%s",past,first[0]);
                        e=e+3;
                        past=e;
                    }
                   break;
                }
                c1=0;
            }
         }
         c=0;
    }
    }
    fprintf(f2,"\t%s","END");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    f4=fopen("symbol_table.txt","w");
    f2=fopen("intermediate_table.txt","r");
    while(!feof(f2))
    {
        fgets(sym,30,f2);
        ts=strtok(sym," \t");
        while(ts!=NULL)
        {
            c2++;
            if(c2==1)
                strcpy(first[0],ts);
            if(c2==2)
                strcpy(second[0],ts);
            ts=strtok(NULL," \t");
        }

        if(c2==4)
        {
            if(fg==0)
            {
                fprintf(f4,"%s\t%s\n",second[0],first[0]);
                strcpy(duplicate[n1],second[0]);
                n1++;
                fg=1;
            }
            else
            {
                for(i=0;i<n1;i++)
                {
                    if((strcmp(second[0],duplicate[i]))==0)
                    {
                        printf("Duplicate found");
                        found=1;
                        fg=1;
                        break;
                    }
                }
                if(found==0)
                {
                    fprintf(f4,"%s\t%s\n",second[0],first[0]);
                    strcpy(duplicate[n1],second[0]);
                    n1++;
                }
            }
        }
     c2=0;
    }
   /* for(j=0;j<n1;j++)
    {
         printf("%s\n",duplicate[j]);
    }*/
}


