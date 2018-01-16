#include"shmfifo.h"

union semun{
	int val;
};

shmfifo_t *shmfifo_init(key_t key, int blksz, int blks)
{
	shmfifo_t *fifo = malloc(sizeof(shmfifo_t));
	assert(fifo);
	memset(fifo, 0, sizeof(shmfifo_t));

	int size = sizeof(shmfifo_t)+ blksz*blks;
	int shmid = shmget(key,0,0);
	if(shmid == -1){//共享受内存不存在需要打开
		shmid = shmget(key, size, IPC_CREAT|0644);
		if(shmid == -1){
			ERR_EXIT("shmid");
		}
		
		fifo->p_shm = shmat(shmid, NULL, 0);
		
		//初始化shmhead
		fifo->p_shm->blksize = blksz;
		fifo->p_shm->blocks = blks;
		fifo->p_shm->rd_index = 0;
		fifo->p_shm->wr_index = 0;
		
		//初始化shmfifo
		fifo->p_payload = (char*)(fifo->p_shm+1);
		fifo->shmid = shmid;
		fifo->sem_mutex = semget(key+1,1,IPC_CREAT|0644);
		fifo->sem_full = semget(key+2,1,IPC_CREAT|0644);
		fifo->sem_empty = semget(key+3,1,IPC_CREAT|0644);
		
		union semun su;
		su.val = 1;
		semctl(fifo->sem_mutex, 0, SETVAL, su);
		su.val = 0;
		semctl(fifo->sem_empty, 0, SETVAL, su);
		su.val = blks;
		semctl(fifo->sem_full, 0, SETVAL, su);

	}else{ //打开共享内存成功
	
	}	
}

static int P(int shmid)
{
	struct sembuf buf[1];
	buf[0].sem_num = 0;
	buf[0].sem_op = -1;
	buf[0].sem_flg = SEM_UNDO;
	return semop(shmid, buf,1);
}
static void V(int shmid)
{
	struct sembuf buf[1];
	buf[0].sem_num = 0;
	buf[0].sem_op = 1;
	buf[0].sem_flg = SEM_UNDO;
	return semop(shmid, buf,1);
}
void shmfifo_put(shmfifo_t *fifo, const void *buf)
{
	P(fifo->sem_full);
	P(fifo->sem_mutex);
	//放入数据
	memset(fifo->p_payload+fifo->p_shm->blksize*fifo->p_shm->wr_index,buf,fifo->shm->blksize);
	fifo->p_shm->wr_index = (fifo->p_shm->wr_index + 1)%fifo->p_shm->blocks; 
	V(fifo->sem_mutex);
	V(fifo->sem_empty);
}

void shmfifo_get(shmfifo_t *fifo, void *buf)
{
	P(fifo->sem_empty);
	P(fifo->sem_mutex);
	//获取数据
	memset(buf,fifo->p_payload+ fifo->p_shm->rd_index*fifo->p_shm->blksize,fifo->p_shm->blksize);
	fifo->p_shm->rd_index = (fifo->p_shm->rd_index-1)%fifo->p_shm->blocks;
	V(fifo->sem_mutex);
	V(fifo->sem_full);

}

void shmfifo_destroy(shmfifo_t *fifo)
{
	shmdt(fifo->p_shm);
	semctl(fifo->sem_empty, 0, IPC_RMID,0);
	semctl(fifo->sem_full, 0, IPC_RMID,0);
	semctl(fifo->sem_mutex, 0, IPC_RMID,0);
	shmctl(fifo->shmid,IPC_RMID,0);
	free(fifo);
}
