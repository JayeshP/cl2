//refered man page of socket and bind(example is given)
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include <netinet/in.h>    //for struct sockaddr_in
int main()
{
	printf("Inception\n");
	int sockfd,cfd;
	struct sockaddr_in my_addr,peer_addr;  
	socklen_t peer_addr_size;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("error in creating socket");
		exit(0);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(10001);
	inet_aton("127.0.0.1",&(my_addr.sin_addr));
	memset(&(my_addr.sin_zero),'\0',8);
	if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr_in))==-1)
	{
		printf("Error in binding");
		exit(0);
	}
	if(listen(sockfd,5)==-1)
		printf("error in listening on port");
	cfd = accept(sockfd,(struct sockaddr*)&peer_addr,&peer_addr_size);
	if(cfd == -1)
		printf("error in accepting request");
	printf("accepted request");
	close(sockfd);
}



/*
1. socket
2. bind
3. listen
4. accept
	a. send
	b. receive
5. close
*/
