#include"../head/SEVERall.h"
int writefilemessage(char *str1,char *str2)
{
    char str[200]={0};
    strcat(str,str2);
    strcat(str,str1);
    fprintf(fp,"%s\n",str);
    fflush(fp);
    return 0;
}



