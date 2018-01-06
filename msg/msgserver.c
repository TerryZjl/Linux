/*************************************************************************
	> File Name: msgclient.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 05 Jan 2018 05:19:08 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct mymsgbuf
{
	long type;
	char buf[1024];
};
int main()
{
	int id = msgget(1234,IPC_CREAT|0644);
	if(id == -1)perror("msgget"),exit(1);
	
	struct mymsgbuf mb, rcvbuf;

	pid_t pid = getpid();
	while(1){
		memset(&mb, 0, sizeof(mb));	
		msgrcv(id , &mb, 1024,1,0);
		mb.type = *(int*)mb.buf;
		msgsnd(id, &mb, strlen(mb.buf+sizeof(int))+sizeof(int),0);
	}
	return 0;	
}
