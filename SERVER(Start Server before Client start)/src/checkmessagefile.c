#include"../head/SEVERall.h"
int findfilebypap()
{
    char path1[20],password1[7];
    printf("\nPLEASE INPUT YOUR PATH TO STORE YOUR FILE:");
    gets(path1);
    char str[100];
    char strcopy[100];
    printf("\nPLEASE INPUT YOUR PASSWORD TO STORE YOUR FILE:");
    gets(password1);
    strcat(path1,password1);
    FILE *file=NULL;
    system("cls");
    printf("FILE NAME:%s\n\n",path1);
    file=fopen(path1,"r");
    if(file==NULL)
    {
        printf("\nFILE NOT EXIST OR YOUR PATH AND PASSWOR WRONG!");
        getch();
        return 0;
    }
    int i=0;

    fscanf(file,"%s:",str);
    printf("CLIENT NAME:%s\n",str);
    printf("\n------------------------\n");
    while(feof(file)==0)
    {
        fscanf(file,"%s",str)  ;
        if(strcopy==str);
            else
        printf("%s ",str);
        i++;
        // printf("%d",i);
        if(i==5)
        {
            printf("\n");
        }
        if(i==6)
        {
            printf("\n------------------------\n");
            i=0;
            strcpy(strcopy,str);
        }
    }
    fclose(file);
    printf("\n\nPRESS ANY KEY TO END WATCHING");
    getch();
    return 1;
}
