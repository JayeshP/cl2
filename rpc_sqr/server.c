#include<rpc/rpc.h>
#include"sqr.h"

static double *square;
double * sqr_1_svc(double *num, struct svc_req *ss)
{
	square = (double *)malloc(sizeof(double));
	*square = *num * *num;		
	return (square);
}
