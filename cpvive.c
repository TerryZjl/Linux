/*************************************************************************
	> File Name: cpvive.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 12 Jan 2018 11:43:27 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler( int a )
{
	printf("begin thing\n");	
	
	sleep(3);
	
	printf("end thing\n");	
}

int main()
{
	sigset_t set;
	sigset_t sig;
	sigset_t pend;
	signal(SIGINT,handler);
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL);
	int i =0;
	for(;i<5;i++){
		printf("copy\n");
		sleep(3);
		printf("end\n");
		sigpending(&pend);
		if(sigismember(&pend, SIGINT)){
			sigsuspend(&sig);
		}
	}
	
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	return 0;
	while(1);
}
