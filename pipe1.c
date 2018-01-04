/*************************************************************************
	> File Name: pipe1.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Wed 03 Jan 2018 03:55:29 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int fds[2];
	if(pipe(fds)==-1)perror("pipe"),exit(1);

	if((pid = fork()) == -1){
		perror("fork");
		exit(2);
	}
	if(pid == 0){
		dup2(fds[1],1);
		close(fds[0]);
		close(fds[1]);
		execlp("ls","ls",NULL);
		exit(3);
	}else{
		dup2(fds[0],0);//本来是wc去标准输入里读，现在取管道读端读
		close(fds[0]);
		close(fds[1]);
		execlp("wc","wc","-l",NULL);
		exit(4);
	}
	return 0;
}
