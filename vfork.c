/*************************************************************************
	> File Name: vfork.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 08 Dec 2017 01:17:02 AM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int a = 111;
int main()
{
	int glob = 222;
	pid_t pid = vfork();

	if(pid == -1)
		perror("vfork");
	if(pid == 0){
		a = 100;
		glob = 200;
		sleep(1);
		printf("child %d, a = %d ,glob = %d\n",getpid(),a,glob);
		//execlp("ls","ls",NULL);
		_exit(1);
	}else {
		printf("parent %d, a = %d, glob = %d\n",getpid(),a,glob);
	}
	return 0;
}
