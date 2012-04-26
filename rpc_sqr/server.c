#include<rpc/rpc.h>
#include "avg.h"

double *sqr_1_svc(numlist *argp, struct svc_req *rqstp)
{
	static double  result;
	int i;
	for(i = 0; i< argp->len; i++)
	{
		result += argp->num[i];
	}
	printf("argument list :%d",argp->len);
	result /= argp->len;
	printf("result : %lf",result);
	return &result;
}

