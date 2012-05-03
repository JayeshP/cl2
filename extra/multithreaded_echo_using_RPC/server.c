/*socket();
bind();
listen();
connect();
recv();
send();
close();
*/
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
void main(int argc,int *argv[])
{
	int sockfd,peerfd,port;
	struct sockaddr_in serv_addr,peer_addr;
	socklen_t peer_len;
	if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
		printf("\nerror in creating socket");
	
	port = atoi(argv[1]);
	printf("\nport : %d",port);
	
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(port);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))==-1)
		printf("\nerror in binding socket");
	listen(sockfd,5);	
	peer_len = sizeof(peer_addr);
	if(peerfd = accept(sockfd,(struct sockaddr *)&peer_addr,&peer_len)==-1)
		printf("\nerror in accepting connection");
	close(sockfd);
}
