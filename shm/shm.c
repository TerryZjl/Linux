/*************************************************************************
	> File Name: shm.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Thu 04 Jan 2018 04:21:11 AM PST
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

struct std{
	int id;
	int age;
	char name[30];
};

int main()
{
	int id = shmget(1234,sizeof(struct std),IPC_CREAT|0644);
	if(id == -1)perror("shmget"),exit(1);
	printf("shmget success\n");
	return 0;
}
