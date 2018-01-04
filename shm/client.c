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
	int id = shmget(1234,0,0);
	if(id == -1)perror("shmget"),exit(1);
	struct std *p = shmat(id,NULL, 0);
	printf("server say:%s",p->name);
	shmdt(p);

	return 0;
}
