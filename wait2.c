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
	/*
	fork();
	printf("1111111111111111111\n");
	if(wait(NULL) == -1){
		perror("wait");
	}

	fork();
	printf("222222222222222222\n");
	if(wait(NULL) == -1){
		perror("wait");
	}

	printf("3333333333333333333\n");
	*/

	fork();
	fork();
	fork();
	printf("3333333333333333333\n");
	return 0;
}

