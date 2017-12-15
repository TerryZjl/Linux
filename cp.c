/*************************************************************************
	> File Name: open.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Thu 14 Dec 2017 05:11:20 AM PST
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	if(argc<3)
	{
		printf("Use: a.out file1 file2\n");
		exit(1);
	}
	int fdin = open(argv[1],O_RDONLY);
	if(fdin == -1){
		perror("open read");
	}
	int fdout = open(argv[2],O_WRONLY|O_CREAT,0644);
	if(fdout == -1){
		perror("open write");
	}
	char buf[1024] = {};
	while(1){
		memset(buf,0,1024);
		int r = read(fdin,buf,1024);
		if(r <= 0){
			break;
		}
		int w =write(fdout,buf,sizeof(buf));
	}
	return 0;
}
