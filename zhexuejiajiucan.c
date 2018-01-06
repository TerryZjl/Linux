/*************************************************************************
	> File Name: zhexuejiajiucan.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 05 Jan 2018 06:44:04 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
#include<unistd.h>

int semid;

union semun{
	int val;
};

void Ptwohand(int no)
{
	int left = no;
	int right = (no+1)%5;

	struct sembuf  sbs[2] = {
		{left, -1, 0},
		{right, -1, 0}
	};
	semop(semid, sbs, 0);
}

void Vtwohand(int no)
{
	int left = no;
	int right = (no+1)%5;

	struct sembuf  sbs[2] = {
		{left, 1, 0},
		{right, 1, 0}
	};
	semop(semid, sbs, 0);
}

//按顺序依次拿筷子会造成死锁
/*
void Phand(int no)
{
	struct sembuf  sbs[1] = {no, -1, 0};
	semop(semid, sbs, 0);
}
void Vhand(int no)
{
	struct sembuf  sbs[1] = {no, 1, 0};
	semop(semid, sbs, 0);
}*/
void philosophere(int no)
{
	while(1){
		printf("no.%d thinking ... \n",no);
		sleep(rand()%5);
		printf("no.%d hungry ... \n",no);
		//按顺序依次拿筷子会造成死锁
		/*Phand(no);
		sleep(1);
		Phand((no+1)%5);*/
		
		//原子的一次拿两个就不会产死死锁
		Ptwohand(no);
		printf("no.%d eating ... \n",no);
		sleep(rand()%3);
		Vtwohand(no);
		/*
		Vhand(no);
		Vhand((no+1)%5);*/
	}	
}

int main()
{
	semid = semget(IPC_PRIVATE, 5,IPC_CREAT|0644);
	if(semid == -1) perror("semget"),exit(1);
	srand(time(NULL));
	union semun su;
	su.val = 1;
	int i = 0;
	for(;i<5;i++){
		semctl(semid, i,SETVAL,su); // 初始化信号里
	}
	int no = 0;
	for(i = 0;i<5;i++){   //创建5个哲学家进程
		pid_t pid = fork();
		if(pid == 0){
			no = i;
			break;
		}
	}
	philosophere(no);
	return 0;
}
