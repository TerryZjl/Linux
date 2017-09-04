#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int creat_daemon()
{  
    //(1)调用umask将文件模式创建屏蔽字设置为0.
    umask(0);    
   //(2)调用fork，父进程退出（exit）。  
    pid_t id = fork();
    if(id > 0)
    {
        exit(1);
    }
    else if(id == 0)
    {
        setsid();         //(3)创建一个新的会话
        if(chdir("/")<0)  //(4)将新建会话的工作目录改成根目录
        {
           perror("chdir");
           return;
        }
       //(5)关闭从父进程继承来的文件
       // close(0);
        //close(1);
        close(2);
       //(6)忽略SIGCHLD信号。
        signal(SIGCHLD, SIG_IGN);
 
    }
}

int main()
{
    creat_daemon();
    while(1);
    return 0;
}

