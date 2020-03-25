#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <WinSock2.h>
#include<pthread.h>
#define PORT 65530
//#pragma comment(lib,"ws2_32.lib")
int main()
{
    int scan;
    WSADATA wsaData;
    while(1)
    {
        if(!WSAStartup(MAKEWORD(1,1),&wsaData) )
        {
            printf("SOCKET ESTABLISHED SUCCESS!\n");
            break;
        }
        else
        {
            printf("socket not established! If continue to establish? Yes press 1;No press 0");
            scanf("%d",&scan);
            if(scan==0)
                exit(0);
            else if(scan==1)
                continue;
            else
            {
                printf("Input err! Late exit!");
                exit(0);
            }
        }
    }
    SOCKET clientsocket=socket(AF_INET,SOCK_STREAM,0);//自己
    SOCKADDR_IN sever;//
    sever.sin_addr.S_un.S_addr=inet_addr("127.0.0.2");//
    sever.sin_family=AF_INET;//
    sever.sin_port=htons(PORT);//对面
    SOCKET seversocket=socket(AF_INET,SOCK_STREAM,0);//
    bind(seversocket,(SOCKADDR*)&sever,sizeof(SOCKADDR));
    connect(clientsocket,(SOCKADDR*)&sever,sizeof(SOCKADDR));
    char recbuf[100];
    while(1)
    {
        if(recv(clientsocket,recbuf,101,0)==0)
            break;
        printf("%s\n",recbuf);
    }
    closesocket(clientsocket);
    WSACleanup();
    printf("SERVICE OUTLINE!");
    system("pause");
    return 0;
}
