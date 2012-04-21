#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>		//for struct sockaddr_in
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
void *myaccept(void *);

void main()
{
        int sockfd,newsockfd;
	struct sockaddr_in serv_addr;         //for AF_INET
	struct sockaddr_in peer_addr;         //used in accept()
	socklen_t peer_len;
        char buf[256];
        pthread_t new_thread;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
		printf("error in socket creation");
	
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(10003);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))==-1)
		printf("error in binding");
	
	if(listen(sockfd,5)==-1)
		printf("error in listening");
	
	peer_len = sizeof(peer_addr);
	
        do
        {
          if((newsockfd=accept(sockfd,(struct sockaddr *)&peer_addr,&peer_len))==-1)
            printf("error while accepting request");
          if(!pthread_create(&new_thread,NULL,myaccept,(void *)newsockfd))
            printf("\nnew thread created");
          
        }while(1);
	close(sockfd);
}
void *myaccept(void *newsockfd1)
{
  char buf[256];
  int newsockfd=(int)newsockfd1;
  int n;
  if(newsockfd==-1)
    {
      printf("error on accept");
      exit(0);
    }
  else
    {
      do
        {
          bzero(buf,sizeof(buf));
          //***newsockfd returned from accept 
          n = recv(newsockfd,buf,sizeof(buf),0);
          if(n<0)  
            printf("\nerror in receiving message from client");
          else 
            printf("\nmessage received :%s",buf);
          if(send(newsockfd,buf,sizeof(buf),0)==-1)
            printf("error in sending msg to client");
        }while(strcmp(buf,"exit\n"));
    }
        //        close(newsockfd);
}
