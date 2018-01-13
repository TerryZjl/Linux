/*************************************************************************
	> File Name: sigaction.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Sat 13 Jan 2018 12:12:57 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler(int a)
{
	printf("aaaaaaaaaaaa\n");
	sleep(3);
}

int mian()
{
	struct sigaction act;
	act.sa_handler =handler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	sigaction(SIGINT, &act, NULL);

	while(1){
		pause();
	}
	return 0;
}
