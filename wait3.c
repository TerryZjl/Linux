/*************************************************************************
	> File Name: wait2.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Thu 07 Dec 2017 03:36:26 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	printf("parent pid = %d \n",getpid());

	int i = 0;
	for(i = 0;i<3;i++)
	{
		if(fork() == 0)
		{
			break;	
		}
	}
	printf("ppid = %d ; pid = %d \n",getppid(),getpid());
	return 0;
}
