#include"idle.h"
#include<stdlib.h>

void main()
{
	CLIENT *client;
	float *idleper;
	struct twono twonum;
	int result;
	idleper = (float *)malloc(sizeof(float));
	client = clnt_create("127.0.0.1",IDLE,VER,"udp");
	idleper = getcpu_1(NULL,client);
	printf("\nIdle percentage is %.2f\n",*idleper);
	twonum.num1 = 1;
	twonum.num2 = 2;
	printf("addition is %d\n",*add_1(&twonum,client));
}
