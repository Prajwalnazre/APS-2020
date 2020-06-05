#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    FILE *fp;
    char text[1000],type[1000],text1[1000];
    int count,progaddr,strlen,flag=1,csaddr;

    fp=fopen("input.txt","r");
    printf("Enter starting address\n");
    scanf("%X",&progaddr);
    csaddr=progaddr;

    while(fgets(text,100,fp)!=NULL)
    {
        if(flag==0)
        {
            csaddr=csaddr+strlen;
            flag=1;
        }
        count=0;
        strcpy(text1,text);
        char *p=strtok(text,"^\n");

        while(p!=NULL)
        {
            if(count==0)
            {
                strcpy(type,p);
            }
             p=strtok(NULL,"^\n");
             count++;
        }
        if(strcmp(type,"H")==0)
        {
            count=0;
            p=strtok(text1,"^");
            while(p!=NULL)
            {
               if(count==1)
               {
                   printf("%s - %X\n",p,csaddr);
               }
               if(count==3)
               {
                   strlen=(int)strtol(p,NULL,16);
               }
               p=strtok(NULL,"^");
               count++;
            }
        }
        if(strcmp(type,"D")==0)
        {
            count=0;
            p=strtok(text1,"^");
            while(p!=NULL)
            {
                if(count%2==1)
                {
                    printf("%s - ",p);
                }
                if(count%2==0 && count!=0)
                {
                    printf("%X\n",csaddr+atoi(p));
                }
                p=strtok(NULL,"^");
                count++;
            }
        }
        if(strcmp(type,"E")==0)
        {
            flag=0;
        }
    }
    fclose(fp);
    return 0;
}


