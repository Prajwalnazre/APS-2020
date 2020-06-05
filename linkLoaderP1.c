#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp,*fw;
    fp = fopen("Input.txt","r");
    fw = fopen("ESTAB.txt","w");
    int progAddr,csAddr,errFlag = 0;
    int csLength,count = 0,i = 0,count2 = 0,progLen;
    char str1[50],type[50][50],csName[50],csLen[50];
    int total;
    char *str2,*duplicate;
    char buff[50];

    printf("\nEnter the starting address please!!\n");
    scanf("%X",&progAddr);

    csAddr = progAddr;
    total = progAddr;

    while(fgets(str1,45,fp) != NULL)
    {
        str2 = strtok(str1," \n");
        //printf("%s\n",str1);
        while(str2!=NULL)
        //while(type[i] != "END")
        {
            if(count == 0)
            {
                strcpy(type[i],str2);
                printf("\nType %s",type[i]);

                if(strcmp(type[i],"H") == 0)
                {
                    str2 = strtok(NULL," \n");
                    strcpy(csName,str2);
                    printf("\n%s",csName);
                    str2 = strtok(NULL," \n");
                    str2 = strtok(NULL," \n");
                    strcpy(csLen,str2);
                    progLen = 0;
                    total = total + progLen;
                    fprintf(fw,"%s\t%X\n",csName,total);
                    printf("\nCS NAME: %s\t CS Length: %s\n",csName,csLen);
                    sscanf(csLen,"%X",&progLen);

                    //printf("Program Length: %X",progLen);
                }

                if(strcmp(type[i],"D") == 0)
                {
                    while(!feof(fw))
                    {
                        fgets(buff,40,fp);
                        duplicate = strtok(buff," \n");
                        if(strcmp(type[i],duplicate))
                        {
                            errFlag = 1;
                            printf("\nDuplicate Found\n");
                        }
                        duplicate = strtok(NULL," \n");
                    }
                }
                i++;
            }



            count++;
            str2 = strtok(NULL," \n");
        }

 /*       if(strcmp(str1,"H") == 0)
        {
            count = 0;

            str2 = strtok(str1," ");
            while(str2 != NULL)
            {
                printf("\nEntered header\n");
                if(count == 0)
                {
                    printf("\n%s\t%X\t",str1,csAddr);
                }
                else if(count == 1)
                {
                    strcpy(csName,str2);
                    printf("Control Section Name = %s",csName);
                    //strLen=atoi(str2);
                    //printf("String Length = %X\n",strLen);
                }
                str2 = strtok(NULL," ");
                count++;
                //printf("Count:%d",count);
            }
        } */
    }
    fclose(fp);
}

