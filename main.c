#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *fp,*fp1;
    char text[1000],type[1000],text1[1000];
    char *p;
    int count,progaddr,cslen,flag=1,csaddr;

    fp=fopen("Input.txt","r");
    fp1=fopen("ESTAB.txt","w");
    printf("Enter starting address\n");
    scanf("%X",&progaddr);
    csaddr=progaddr;

    while(fgets(text,100,fp)!=NULL)
    {
        if(flag==0)
        {
            csaddr=csaddr+cslen;
            flag=1;
        }
        count=0;
        strcpy(text1,text);
        p=strtok(text," \n");

        while(p!=NULL)
        {
            if(count==0)
            {
                strcpy(type,p);
            }
             p=strtok(NULL," \n");
             count++;
        }
            if(strcmp(type,"H")==0)
            {
                count=0;
                p=strtok(text1," ");
                while(p!=NULL)
                {
                    if(count==1)
                    {
                       // duplicate(p);
                        printf("%s - %X\n",p,csaddr);
                        fprintf(fp1,"%s - %X\n",p,csaddr);
                    }
                    if(count==3)
                    {
                        cslen=(int)strtol(p,NULL,16);
                    }
                    p=strtok(NULL," ");
                    count++;
                }
            }
            if(strcmp(type,"D")==0)
            {
                count=0;
                p=strtok(text1," ");
                while(p!=NULL)
                {
                    if(count%2==1)
                    {
                       // duplicate(p);
                        printf("%s - ",p);
                        fprintf(fp1,"%s - ",p);
                    }
                    if(count%2==0 && count!=0)
                    {
                        printf("%X\n",csaddr+(int)strtol(p,NULL,16));
                        fprintf(fp1,"%X\n",csaddr+(int)strtol(p,NULL,16));
                    }
                    p=strtok(NULL," ");
                    count++;
                }
            }
            if(strcmp(type,"E")==0)
            {
                flag=0;
            }
        }
            fclose(fp);
            fclose(fp1);
            return 0;
}

void duplicate(char p1[100])
{
    printf("p1=",&p1);
    FILE *fp2;
    fp2=fopen("ESTAB.txt","r");
    char buf[1000],*token,val[100];
    int cnt=0;


    while(!feof(fp2))
    {
        fgets(buf,100,fp2);
        token = strtok(buf," \n");
         while(token!=NULL)
        {
            if(cnt==0)
            {
                strcpy(val,token);
                 if(strcmp(p1,val)==0)
                {
                    printf("Duplicate found\n");
                }
                else
                {return p1;}
            }
            token = strtok(NULL," \n");
        }

    }
    fclose(fp2);
    return 0;

}
