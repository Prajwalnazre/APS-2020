#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fr, *fw;
    int  cnt = 0;
    char *token, str[100];
    //char *var1, *var2;
    char a1[100][100];
    char a2[100][100];
    fr = fopen("INTERMEDIATE.txt","r");
    fw = fopen("SYMBOL_TABLE.txt","w");

    while(!feof(fr))
    {
        fgets(str,32,fr);
        token = strtok(str," \t\n");

        while(token != NULL)
        {
            cnt++;
            printf("%s\n",token);

            if(cnt == 2)
                strcpy(a1[0],token);
            if(cnt == 1)
                strcpy(a2[0],token);

            token = strtok(NULL," \t\n");
        }

        if(cnt == 4)
        {
            fprintf(fw,"%s\t",a1[0]);
            fprintf(fw,"%s\n",a2[0]);
        }
        if(cnt == 1 || cnt == 2 || cnt == 3)
        {
            fprintf(fw,"%s\t"," ");
            fprintf(fw,"%s\n",a2[0]);
        }
        cnt = 0;
        strcpy(a1,"");
        strcpy(a2,"");
    }

    printf("Data saved\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
