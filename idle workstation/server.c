#include "idle.h"

float *
getcpu_1_svc(void *argp, struct svc_req *rqstp)
{
	static float  result;
	FILE *fp;
	
	system("mpstat > temp.txt");
	fp = fopen("temp.txt","r");
	fseek(fp,-6,SEEK_END);
	fscanf(fp,"%f",&result);
	return &result;
}
int *
add_1_svc(struct twono *argp, struct svc_req *rqstp)
{
	static int  result;
	result = argp->num1+argp->num2; 
	
	return &result;
}

