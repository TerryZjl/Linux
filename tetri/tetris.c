/*************************************************************************
	> File Name: tetri.c
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Thu 11 Jan 2018 03:12:28 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include"keyboard.h"

#define FC 5
#define BC 0



void show_element(int x, int y,int c)
{
	++x;
	++y;
	x *= 2;
	printf("\033[%d;%dH",y,x); //x列y行
	printf("\033[03%dm\033[04%dm[]\033[0m",c,c);
	fflush(stdout);
}
struct shape{
	int data[5][5];
}shapes[1] = {
	{
	 0 , 0 , 0 , 0 , 0,
	 0 , 0 , 1 , 0 , 0,
	 0 , 1 , 1 , 1 , 0,
	 0 , 0 , 0 , 0 , 0,
	 0 , 0 , 0 , 0 , 0
	}
};
struct shape empty[1] = {
	{
	 0 , 0 , 0 , 0 , 0,
	 0 , 0 , 0 , 0 , 0,
	 0 , 0 , 0 , 0 , 0,
	 0 , 0 , 0 , 0 , 0,
	 0 , 0 , 0 , 0 , 0
	}
};
void show_shape(struct shape* sp, int x, int y)
{
	int i,j;
	for(i = 0;i<5;i++) //行
	{
		for(j = 0;j<5;j++) //列
		{
			if(sp->data[i][j] == 1){
				show_element(x+j, y+i,FC);	
			}else{
				show_element(x+j, y+i,BC);	
			}
		}
	}
}

struct shape *p = &shapes[0];
int g_x = 10;
int g_y = 0;

void tetris_timer(struct shape* sp)
{
	show_shape(shapes, g_x,g_y);
	g_y++;
}



static void handler(int s)
{
	tetris_timer(p);
}

int main()
{
	signal(SIGALRM, handler);
	struct itimerval it;
	it.it_value.tv_sec = 0;
	it.it_value.tv_usec = 1;
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 1;
	//定时器
	setitimer(ITIMER_REAL,&it, NULL);
	
	//控制键盘,非标准输入
	init_keyboard();

	while(1){
		int c = get_key();
		if(is_up(c)){
			g_y--;
			show_shape(shapes, g_x,g_y);
		}else if(is_down(c)){
			g_y++;
			show_shape(shapes, g_x,g_y);
		}else if(is_left(c)){
			show_shape(empty,g_x,g_y);
			g_x-=2;
			show_shape(shapes, g_x,g_y);
		}else if(is_right(c)){
			show_shape(empty,g_x,g_y);
			g_x+=2;
			show_shape(shapes, g_x,g_y);
		}
		//pause();
	}
	recover_keyboard();
	/*while(1){
		pause();
	}*/
	
	/*	int i = 0;
	for(;i<5;i++)
	{
		show_element(10,i-1,7);	
		show_element(10,i,5);	
		sleep(1);
	}*/


	return 0;
}

