/*************************************************************************
	> File Name: mysleep.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Thu 28 Dec 2017 10:03:42 PM PST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

void handler()
{}

void mysleep(int timeout)
{
	struct sigaction ack, oack;
	ack.sa_handler = handler;
	sigemptyset(&ack.sa_mask);
	ack.sa_flags = 0;
	sigaction(SIGALRM, &ack, &oack);
	alarm(3);
	int i = pause();
	//printf("i=%d",i);
	alarm(0);
	sigaction(SIGALRM, &oack, NULL);
}

int main()
{
	while(1)
	{
		printf("myslepp 3s \n");
		mysleep(3);
	}
	return 0;
}
