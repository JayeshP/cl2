#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>		//otherwise gives error i bcopy
#include<string.h>
#include<stdlib.h>
void main()
{
	int sockfd;		//file descriptor for socket
	struct sockaddr_in serv_addr;
	struct hostent *server;			//******
        char buf[256]="HI I am Jayesh";
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
          printf("error in socket creation");
	else 
          printf("\nsocket created");
	server = gethostbyname("127.0.0.1");
	if (server == NULL) {
          fprintf(stderr,"ERROR, no such host\n");
          exit(0);
        }
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	
	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);			//******see &serv_addr very important
        serv_addr.sin_port = htons(10003);	//****
	if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
          printf("\nerror in connecting to server socket");
	else 
          printf("\nconnected");

        //sockfd for socket
        do
          {
            printf("enter echo message :");
            fgets(buf,sizeof(buf),stdin);
            if(send(sockfd,buf,sizeof(buf),0)==-1)  
              printf("error in sending message to server");
            bzero(buf,sizeof(buf));
            if(recv(sockfd,buf,sizeof(buf),0)==-1)
              printf("error in receiving msg from server");
            printf("\nmessage from server : %s",buf);
          }while(strcmp(buf,"exit\n"));
	close(sockfd);

}

