#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int startserver()
{
	struct addrinfo hint,*res,*p;
	int sockfd;	
	char port[] = "10004";
	bzero((char *)&hint,sizeof(hint));
	hint.ai_family = AF_INET;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL,port,&hint,&res);
	for(p=res;p!=NULL;p=p->ai_next)
	{
		if((sockfd = socket(p->ai_family,p->ai_socktype,0))==-1)
			continue;
		if(bind(sockfd,p->ai_addr,p->ai_addrlen)==0) break;
		/*p->ai_addr,p->ai_addrlen*/
	}
	freeaddrinfo(res);
	listen(sockfd,5);
	return sockfd;
}
void respond(int clientfd)
{
	char buf[10000];
        int byte_read;
        bzero(buf,10000);
	byte_read = recv(clientfd,buf,10000,0);
	printf("\nHTTP HEADER : %s",buf);
	if(send(clientfd,buf,strlen(buf),0)==-1)
          printf("\nerror in sending response to browser");
	shutdown (clientfd, SHUT_RDWR); 
	close(clientfd);
}
int main()
{
	int sockfd,clientfd;
	struct sockaddr_in client;  //***sockaddr_in
	socklen_t clntlen;
	sockfd = startserver();
	clntlen = sizeof(client);
	while(clientfd)
	{
		if((clientfd = accept(sockfd,(struct sockaddr *)&client,&clntlen))>-1)	
                  respond(clientfd);	
	      
	}
        return 0;
}
