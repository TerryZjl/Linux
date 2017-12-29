/*************************************************************************
	> File Name: pending.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Fri 29 Dec 2017 02:36:54 AM PST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

void printpend(sigset_t *pset, sigset_t* oset)
{
	for(i = 1;i<32;i++)
	{
		if(sigismember(oset, i)){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	putchar('\n');
	int i = 1;
	for(;i<32;i++){
		if(sigismember(pset,i))
		{
			putchar('1');
		}else{
			putchar('0');
		}
	}
	putchar('\n');
}

int main()
{
	sigset_t set,pset,oset;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	sigprocmask(SIG_BLOCK,&set,&oset);
	while(1)
	{
		sigpending(&pset);
		printpend(&pset,&set);	
		sleep(1);
	}
	return 0;
}
