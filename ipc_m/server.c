#include"comm.h"

int main()
{
	int shmid = CreateShm(4097);
	printf("%d\n",shmid);
	if(shmid < 0 )
	{
		return 2;
	}
	char* buf = shmat(shmid, NULL, 0);
	int i =0;
	while(1)	
	{
		buf[i++] = 'A';
		buf[i] = 0;
		sleep(1);
	}
	DeleteShm(shmid);


	return 0;
}
