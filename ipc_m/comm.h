#ifndef _COMM_H_
#define _CONN_H_

#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/types.h>

#define PATHNAME "."
#define SIZE 0x6666

int CreateShm(size_t size);
int GetShm(size_t size);
int DeleteShm(int shmid);

#endif
