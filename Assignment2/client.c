#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/un.h>
#include <netinet/in.h>
int main()
{
	printf("client started");
	int cfd,sockfd;
	struct sockaddr_in addr;
	
	socklen_t addrlen;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("error in creating socket");
		exit(0);
	}
    bzero((char *) &addr, sizeof(addr));							//*******
	addr.sin_family = AF_INET;
	addr.sin_port = htons(10001);
	cfd = connect(sockfd,(struct sockaddr*)&addr,sizeof(struct sockaddr_in));
	if(cfd==-1)
		printf("\nerror in connecting to server in client\n");
	printf("connected");
	close();
}

/*
1. socket
2. connect
	a. send
	b.receive
3.close
*/
