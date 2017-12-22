#include"comm.h"

static int Comm(size_t size,int flgs)
{
	key_t key = ftok(PATHNAME,SIZE); 
	if(key < 0){
		perror("ftok");
		return 1;
	}

	int shmid = shmget(key, size, flgs);
	if(shmid == -1)
	{
		perror("shmget");
		return shmid;
	}
	return shmid;
}


int CreateShm(size_t size)
{
	return Comm(size, IPC_CREAT|IPC_EXCL|0666);
}

int GetShm(size_t size)
{
	return Comm(size,IPC_CREAT);
}


int DeleteShm(int shmid)
{
	if(shmctl(shmid, IPC_RMID, NULL) <0)
	{
		perror("shmctl"); 
		return 2;
	}
}
