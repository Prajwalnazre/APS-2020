#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fp1,*fp2,*fp3;
   char temp1[100],text[100],text1[100],text2[100],type[100],name[100],name1[100],estab[100],objectcode[100][100];
   char *p,lab[100][100],address[100][100];
   int location[100],cslen;
   int count,count1,x=0,y=0,i,j,temp,flag,flag2,num1;
   fp1=fopen("Input.txt","r");
   fp2=fopen("ESTAB.txt","r");
   fp3=fopen("Output.txt","w");

   while(fgets(estab,100,fp2)!=NULL)
   {
       count=0;
       p=strtok(estab,"\t\n");
       while(p!=NULL)
       {
           if(count==0)
           {
                strcpy(lab[y],p);

           }
           if(count==1)
           {
                strcpy(address[y],p);
                y++;
           }
           p=strtok(NULL,"\t\n");
           count++;
       }
   }
   while(strcmp(text,"END")!=0)
   {
       fgets(text,100,fp1);
       count=0;
       strcpy(text1,text);
       p=strtok(text," \n");
       while(p!=NULL)
       {
           if(count==0)
                strcpy(type,p);
           p=strtok(NULL," \n");
           count++;
       }
       if(strcmp(type,"H")==0)
       {
           count=0;
           p=strtok(text1," \n");
           while(p!=NULL)
           {
            if(count==1)
                strcpy(name,p);
            if(count==3)
                cslen=(int)strtol(p,NULL,16);
            p=strtok(NULL," \n");
            count++;
           }
       }
       if(strcmp(type,"T")==0)
       {
            count=0;
            p=strtok(text1," \n");
            while(p!=NULL)
            {
                if(count==1)
                {
                    for(i=0;i<y;i++)
                    {
                        if(strcmp(name,lab[i])==0)
                        {
                            location[x]=(int)strtol(p,NULL,16)+(int)strtol(address[i],NULL,16);
                        }
                    }
                }
                if(count!=0 && count !=1)
                {
                    strcpy(objectcode[x],p);
                    x++;
                    location[x]=location[x-1]+(strlen(objectcode[x-1]))/2;
                }
                p=strtok(NULL," \n");
                count++;
            }
       }
       if(strcmp(type,"M")==0)
       {
           count1=0;
           strcpy(text2,text1);
           char *p1=strtok(text2," \n");
           while(p1!=NULL)
           {
             if(count1==2)
             {
                 if(strcmp(p1,"05")==0)
                    flag=1;
                 else
                    flag=0;
             }
             if(count1==3)
             {
                strcpy(name1,p1);
                if(name1[0]=='+')
                    flag2=1;
                else
                    flag2=0;
                strcpy(name1,&p1[1]);

                count=0;
                p=strtok(text1," \n");
                while(p!=NULL)
                {
                    if(count==1)
                    {
                        for(i=0;i<y;i++)
                        {
                            if(strcmp(name,lab[i])==0)
                            {
                                temp=(int)strtol(p,NULL,16)+(int)strtol(address[i],NULL,16);
                            }
                        }
                        for(i=0;i<x;i++)
                        {
                            if((location[i]==temp && flag==0)|| (location[i]==(temp-1) && flag==1))
                            {
                                for(j=0;j<y;j++)
                                {
                                    if(strcmp(name1,lab[j])==0)
                                    {
                                        if(flag2==1)
                                            num1=(int)strtol(objectcode[i],NULL,16)+(int)strtol(address[j],NULL,16);
                                        else
                                            num1=(int)strtol(objectcode[i],NULL,16)-(int)strtol(address[j],NULL,16);
                                        itoa(num1,temp1,16);
                                        strcpy(objectcode[i],temp1);
                                    }
                                }
                            }
                        }
                    }
                    p=strtok(NULL," \n");
                    count++;
                }

             }
             p1=strtok(NULL," \n");
                count1++;
           }
       }
    }
    for(i=0;i<x;i++)
    {
        printf("%06X\t%06s\n",location[i],objectcode[i]);
        fprintf(fp3,"%06X\t%06s\n",location[i],objectcode[i]);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
   return 0;
}
