#include"../head/SEVERall.h"
int main()
{
    int A;
    while(1)
    {
        printf("\t\tPLEASE CHOOSE THE FUNC TO USE:\n");
        printf("1.BEGIN TO COMMUNICATE\t2.CHECK THE RECENT MESSAGE FILE\t3.EXIT");
        A=getch();
        switch(A)
        {
        case '1':
            system("cls");
            start();
            continue;
        case '2':
            system("cls");
            findfilebypap();
            system("cls");
            continue;
        case'3':
            exit(0);
        }
    }

    return 0;
}
