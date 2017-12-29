/*************************************************************************
	> File Name: sigchld.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 29 Dec 2017 04:20:50 AM PST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void handler(int sig)
{
	//printf("sig= %d\n",sig);
	pid_t ret;
	while(1)
	{
		switch(ret=waitpid(-1,NULL, WNOHANG))
		{
			case 0:
			case -1:
				return;
			default:
				printf("waitpid= %d success!!\n",ret);
				break;
		}
	}
}

int main()
{
	signal(17, handler);
	pid_t pid;
	int i = 0;
	for(;i<10;i++){
		if((pid =fork())==0)
		{
			break;
		}
	}
	if(pid == 0){
		printf("i am chlid = %d\n",getpid());
		_exit(1);
	}else if(pid > 0){
		while(1){
	    printf("parent pid = %d\n",getpid());
		sleep(1);
		}
	}else{
		perror("fork");
	}

	return 0;
}
