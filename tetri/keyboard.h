/*************************************************************************
	> File Name: keyboard.h
	> Author: 赵嘉龙
	> Mail: avltree@163.com 
	> Created Time: Thu 11 Jan 2018 04:19:49 AM PST
 ************************************************************************/
#ifndef KEYBOARD_H
#define KEYBOARD_H
int init_keyboard(void);
void recover_keyboard(void);
int get_key(void);
int is_up(int key);
int is_down(int key);
int is_left(int key);
int is_right(int key);
int is_enter(int key);	
int is_esc(int key);
int is_space(int key);
#endif

