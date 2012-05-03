/*
socket();
connect();
send();
recv();
close();
*/
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdio.h>
#include<netdb.h>
void main(int argc,char *argv[])
{
	int sockfd,port;
	char buf[256];
	struct sockaddr_in serv_addr;
	struct hostent *server;
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
		printf("\nerror in creating socket");
	
	port = atoi(argv[2]);
	printf("\nport : %d \nhost :%s",port,argv[1]);
	//server = gethostbyname(argv[1]);
	
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(port);
	inet_aton(argv[1],(struct in_addr *)&serv_addr.sin_addr.s_addr);
	//bcopy((char *)server->h_addr,(char * )&serv_addr.sin_addr.s_addr,server->h_length);
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))==-1)
		printf("\nerror in connecting to server\n");
		
	do
    {
		printf("enter echo message :");
        fgets(buf,sizeof(buf),stdin);
        if(send(sockfd,buf,sizeof(buf),0)==-1)  
        	printf("error in sending message to server");
        printf("\nrecieving message");
        bzero(buf,sizeof(buf));
        if(recv(sockfd,buf,sizeof(buf),0)==-1)
        	printf("error in receiving msg from server");
        printf("\nmessage from server : %s",buf);
  	}while(strcmp(buf,"exit\n"));
	close(sockfd);
	printf("\n");
}
