/*************************************************************************
	> File Name: locker.h
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Sat 20 Jan 2018 06:57:59 PM PST
************************************************************************/

#ifndef __LOCKER_H_
#define __LOCKER_H_

#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<excption>

using namespace std;

class sem
{
public:
	sem(int pshared= 0,unsigned int value = 0)
	{
		if(sem_init(&m_sem, pshared, value)!=0){
			throw exception();		
		}
	}
	~sem()
	{
		sem_destroy(&m_sem);
	}
	bool P()
	{	
		return 0 == sem_wait(&m_sem);
	}

	bool V()
	{
		return 0 == sem_post(&m_set);
	}
private:
	sem_t m_sem;		
};

class locker
{
public:
	locker()
	{
		if(pthread_mutex_init(&m_mutex, NULL)!=0){
			throw exception();
		}
	}
	~locker()
	{
		pthread_mutex_destroy(&m_mutex);
	}

	bool lock()
	{
		return 0 == pthread_mutex_lock(&m_mutex);
	}
	bool unlock()
	{
		return 0 == pthread_mutex_unlock(&m_mutex);
	}

private:
	pthread_mutex_t m_mutex;
};


class cond
{
public:
	cond()
	{
		if(pthread_cond_init(&m_cond, NULL) != 0 )
		{
			throw exception();
		}
	}
	~cond()
	{
		pthread_cond_destroy(&m_cond);
	}
	
	bool signal()
	{
		return 0 == pthread_cond_signal(&m_cond);
	}
	bool wait(pthread_mutex_t m_mutex)
	{
		return 0 == pthread_cond_wait(&m_cond, &m_mutex);
	}
private:
	pthread_cond_t m_cond;
};
#endif


