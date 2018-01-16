#include"shmfifo.h"

typedef struct data{
	int id;
	char name[32];
}student;


int main()
{
	int key =  ftok(PATH, PRO_ID);
	shmfifo_t *p = shmfifo_init(key,sizeof(student),3);
	student st[10] = {
		{1,"aa"},
		{2,"bb"},
		{3,"cc"},
		{4,"dd"},
		{5,"ee"},
		{6,"ff"},
		{7,"gg"},
		{8,"hh"}
	};
	int i = 0;
	for( i = 0; i <8;i++){
		shmfifo_put(p, st+i);
		printf("put %d\n",st[i].id);
	}
	return 0;
}
