#include"httpd.h"

#define SIZE 64

void Usage(char *argv)
{
    printf("Usage\n\t%s [ip] [port]\n", argv);
}

int main(int argc, char* argv[])
{
    if(argc<3){
        Usage(argv[0]);
        return 1;
    }
    int listenfd = Getlistenfd(argv[1],atoi(argv[2]));
    printf("get listenfd\n");
   
	//创建epoll模型
	int epfd = epoll_create(SIZE);

	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = listenfd;
	
	//用户自定义就绪队列
	struct epoll_event revent[50];
	int rev_len = sizeof(revent)/sizeof(revent[0]);
	int num = 0;
	int timeout =-1;
	
	//将监听套接字添加到红黑树中
	if(epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev)){
		perror("epoll_ctl");
		return 2;
	}
	
	//处理多路转接
	while(1){
		num = epoll_wait(epfd, revent, rev_len, timeout);
		switch(num)
		{
			case 0:
			{
				printf("timeout.....");
				break;
			}	
			case -1:
			{
				perror("epoll_wait");
				break;
			}
			default://有事件已就绪
			{
				int i = 0;
				for(i = 0;i<num;i++){
					int fd = revent[i].data.fd;
					if(fd == listenfd){
						
					}//if(fd == listenfd)
					if(fd != listenfd){
					
					}//if( fd != listenfd)
				}//for

				break;	
			}
		}
	}
	/*while(1)
    {
        printf(".........\n");
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        int new_sock = accept(listenfd, (struct sockaddr*)&client, &len);
        printf("accept new sock \n");
        pthread_t id;
        pthread_create(&id, NULL,  handler_request, (void*)new_sock);
     
        printf("wwwwwwwwwwwwww\n");
        pthread_detach(id);
        printf("sssssssssssssss\n");
    }*/
    return 0;
}
