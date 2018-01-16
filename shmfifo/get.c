#include"shmfifo.h"


typedef struct data{
	int id;
	char name[32];
}student;


int main()
{	
	int key = ftok(PATH, PRO_ID);
	shmfifo_t* p = shmfifo_init(key,sizeof(student),3);
	student buf;
	int i = 0;
	for(i = 0;i<8;i++){
		sleep(1);
		shmfifo_get(p,&buf);
		printf("get id = %d, name = %s\n",buf.id,buf.name);
		memset(&buf,0x00,sizeof(student));
	}
	shmfifo_destroy(p);
	return 0;
}
