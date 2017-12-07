/*************************************************************************
	> File Name: wait1.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Thu 07 Dec 2017 02:56:05 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		exit(1);
	}
	if(pid == 0){
		int i = 0;
		while(1){
			//if(++i == 3)break;
			printf("aaaaaaaaaaapid:%d\n",getpid());
			sleep(1);
		}
	}
	else{
		int status;
		pid_t w = wait(&status);
		if(w == -1)
		{
			perror("wait");
		}
		else{
		    printf("ret w = %d\n",w);
		}

		if(WIFEXITED(status))
		{
			printf("exit code = %d\n",WEXITSTATUS(status));
		}else if(WIFSIGNALED(status)){
			printf("SIG code = %d\n",WTERMSIG(status));
		}
	}
	return 0;
}

