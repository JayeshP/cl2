#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<netdb.h>
void main()
{
	int sockfd;
	int i;
	struct hostent *server;
	server = gethostbyname("127.0.0.1");
	for(i=0;i<65535;i++)
	{
		
		struct sockaddr_in serv_addr;
		
		if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
			printf("\nerror in socket creation");
			
		bzero((char *)&serv_addr,sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(i);
		inet_aton("127.0.0.1",(struct in_addr*)&serv_addr.sin_addr);
		//serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
		//serv_addr.sin_addr.s_addr = htonl(gethostbyname("127.0.0.1"));
		
		if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))!=-1)
			printf("\nopen %d",i);
			
		close(sockfd);
	}
}

