/*************************************************************************
	> File Name: pipe.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Wed 03 Jan 2018 03:39:05 AM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fds[2];
	int ret =pipe(fds);
	if(ret  == -1)perror("pipe"),_exit(1);
	pid_t pid = fork();
	if(pid < 0 )perror("fork"),_exit(2);
	
	if(pid == 0){//child
		close(fds[0]);
		char* str = "cang lao shi jie hun le";
		int i = 0;
		while(1){
			write(fds[1],str, strlen(str));
			++i;
			if( i == 10){
				break;
			}
		}
		close(fds[1]);
	}else{//father
		close(fds[1]);
		char buf[4096] = {};
		while(1){
			sleep(2);
			int r = read(fds[0],buf,4096);
			printf("%dfather say: %s\n",r, buf);
			memset(buf,0,4096);
		}
	}
	return 0;
}
