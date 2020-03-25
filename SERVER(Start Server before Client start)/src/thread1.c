#include"../head/SEVERall.h"
void *thread1()
{
    SOCKADDR_IN clntAddr;
    int clientSize=sizeof(SOCKADDR);
    pthread_t q12;
    pthread_create(&q12,NULL,(void*)pid1,NULL);
    SOCKET clntSock=accept(SERVERsocket,(SOCKADDR*)&clntAddr,&clientSize);//********accept
    a=(int)(clntSock);
    system("cls");
    char str[200];
    int is;
    char* timenow;
    printf("AT YOUR SERVICE!:%s:%d\n",inet_ntoa(clntAddr.sin_addr),(clntAddr.sin_port));
    printf("------------------------------------------------");
    fprintf(fp,"%s:%d\n",inet_ntoa(clntAddr.sin_addr),(clntAddr.sin_port));
    while(1)
    {
        printf("\nPLEASE INPUT YOUR MESSAGE (PRESS ENTER TO SEND)(NO MORE THAN 150 WORDS):\n\n");
        gets(str);
        send(clntSock,str,strlen(str)+sizeof(char),0);
        time_t t;//定义一个时间变量
        t=time(NULL);
        timenow=ctime(&t);
        printf("\nSEND SUCCESS! %s\nPRESS 1 TO CNOTINUE,NO PRESS 0",timenow);
        printf("\n------------------------------------------------");
        writefilemessage(str,timenow);
        is=getch();
        //    system("cls");
        if(is=='0')
        {
            closesocket(clntSock);
            printf("\nWETHER TO PRESEVE THE MESSAGE TO THE LOCAL FILE?PRESS 1 TO CNOTINUE,NO PRESS ANY KEY ");
            is=getch();
            if(is=='1')
            {
                printf("\nPLEASE REMEBER THE PASSWORD YOU HAD INPUT:%s",password);
                return 0;
            }
            else
            {
                fclose(fp);
                fp=fopen(filepath,"w");
                fclose(fp);



                return 0;
            }

        }
        else if(is=='1')
            continue;
        else
        {
            printf("\nInput err! Late exit!");
            fclose(fp);
            system("pause");
            return 0;
        }
    }

}
