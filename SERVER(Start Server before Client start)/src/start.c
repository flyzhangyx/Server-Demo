#include"../head/SEVERall.h"
int start()
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
    check_in();//PASSWORD
    SERVERsocket=socket(AF_INET,SOCK_STREAM,0);
    SOCKADDR_IN localAddr;
    localAddr.sin_family=AF_INET;
    localAddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.2");//inet_addr IP转换成字符串，INADDR_ANY是本机IP 127.0.0.1自测IP
    localAddr.sin_port=htons(PORT);//我的程序调用的端口,为0表示随机,htons()一个转换函数
    int b= bind(SERVERsocket,(SOCKADDR*)&localAddr,sizeof(SOCKADDR));
    if(b!=0)
    {
        printf("IP/PORT BIND ERROR!");//检测绑定是否成功
        exit(0);
    }
    while(listen(SERVERsocket,5)==0)//阻塞
    {
        pthread_t q1;
        pthread_create(&q1,NULL,thread1(),NULL);
        system("cls");
        printf("Waiting for user connections!");
    }
    closesocket(SERVERsocket);
    WSACleanup();
    return  0;
}
