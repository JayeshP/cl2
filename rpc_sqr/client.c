#include<rpc/rpc.h>
#include"avg.h"
#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
void main(int argc,char *argv[])
{
	double *num2;
	int i;
	char *host;
	CLIENT *client;
	host=argv[1];
	numlist list;
	list.len = argc-2;
	for(i=2;i<argc;i++)
	{
		list.num[i-2] = atoi(argv[i]);
		printf("%d",list.num[i-2]);
	}
	client = clnt_create("127.0.0.1",SQRPROGRAM,SQRVER,"udp");
	num2 = sqr_1(&list,client);
	printf("\naverage is : %lf\n",*num2);
}
