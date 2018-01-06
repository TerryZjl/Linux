/*************************************************************************
	> File Name: mutex.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 05 Jan 2018 05:56:38 PM PST
 ************************************************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>
#include<sys/sem.h>
#include<stdlib.h>


int id;
int P()
{
	struct sembuf sb[1] = {0,-1,0};
	return semop(id, sb,1);
}
int V()
{
	struct sembuf sb[1] = {0,1,0};
	return semop(id, sb,1);
}
void print(char c)
{
	int i =0;
	for(;i<10;i++){
		P();		
		printf("%c",c);
		fflush(stdout);
		sleep(rand()%3);
		printf("%c",c);
		fflush(stdout);
		sleep(rand()%3);
		V();
	}
}

union semun{
	int val;
};
int main()
{
	id = semget(1234,1,IPC_CREAT|0644);
	if(id == -1)perror("semget"),exit(1);
	union semun su = {1};//联合体一般不写初始化，若初始化只能初始化联合体里面第一个	
	semctl(id,0,SETVAL,su);
	srand(time(NULL));
	pid_t pid = fork();
	if(pid == -1)perror("fork"),exit(1);

	if(pid == 0){
		print('O');
	}else{
		print('X');	
	}
	return 0;	
}
