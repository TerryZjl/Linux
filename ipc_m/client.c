/*************************************************************************
	> File Name: client.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Thu 21 Dec 2017 05:49:09 PM PST
 ************************************************************************/
#include"comm.h"

int main()
{
	int shmid = GetShm(4097);
	printf("get shmid : %d\n",shmid);
	if(shmid < 0 )
	{
		return 2;
	}
	while(1)
	{

	char* buf = shmat(shmid, NULL, 0);
	printf("%s\n",buf);
	}
	return 0;
}
