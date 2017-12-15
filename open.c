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
int main()
{
	int fd = open("mmc",O_RDWR);
	if(fd == -1){
		perror("open");
	}
	char buf[1024] = {};
	int r = read(fd, buf, 1024);
	if(r == -1){
		perror("read");
	}
	printf("r = %d, buf = [%s]\n",fd, buf);
	return 0;
}
