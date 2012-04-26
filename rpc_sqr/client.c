#include<rpc/rpc.h>
#include"sqr.h"
//#include<stdio.h>
//#include<stdlib.h>
void main()
{
	double num1=4,*num2;
	CLIENT *client;		
	client = clnt_create("127.0.0.1",SQRPROGRAM,SQRVER,"udp");
	num2 = sqr_1(&num1,client);
	printf("\nsquare of 4 is : %lf",*num2);
}
