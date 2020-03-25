#include"../head/SEVERall.h"
int check_in()
{
    do
    {
        printf("PLEASE INPUT YOUR NUM TO ACCSESS THE SYSTEM(FOR SIX INTEGER NUMBERS):");
        gets(password);
        printf("\nPLEASE INPUT YOU PATH TO STORE THE FILE:");
        gets(filepath);
        strcat(filepath,password);
        printf("%s\n",filepath);
        fp = fopen(filepath,"a+");
        if(fp==NULL)
        {
            printf("\nOPEN FILE ERROR!BUT YOU CAN STILL USE IT\n");
            system("pause");
            system("cls");
        } //如果文件能成功打开，函数返回值不为NULL
    }
    while(fp==NULL);
    return 0;
}
