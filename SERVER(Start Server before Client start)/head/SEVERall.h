#ifndef SEVERALL_H_INCLUDED
#define SEVERALL_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<WinSock2.h>
#include<pthread.h>
#include<time.h>
#include<string.h>
#define PORT 65530
//#pragma comment(lib,"ws2_32.lib")
int a;
int start();
void *thread1();
void *thread2();
void *pid1();
int check_in();
int writefilemessage(char *str1,char *str2);
int findfilebypap();
struct interf
{

} Q;
SOCKET SERVERsocket;
char password[7];
FILE *fp;
char filepath[20];
#endif // SEVERALL_H_INCLUDED
