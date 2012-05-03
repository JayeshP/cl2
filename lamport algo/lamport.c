/*	
	see sleep management : when 1 process sends message to 2nd one, then in between message delivery,time clock of 1st should not get updated.
	for that, addition  of sleep() in clock functions should be less than sleep in increment function.
*/
#include<pthread.h>
#include<stdio.h>


int clk_t_1 = 0,clk_t_2 = 0,clk_t_3 = 0;
int sender = 1;
pthread_mutex_t var;
void *increament1(void *interval)
{
	int *interval1 = (int *)interval;
	while(1)
	{
		clk_t_1 += *interval1;
		printf("\nclk1 : %d",clk_t_1);
		sleep(3);
	}
}
void *increament2(void *interval)
{
	int *interval2 = (int *)interval;
	while(1)
	{
		clk_t_2 += *interval2;
		printf("\nclk2 : %d",clk_t_2);
		sleep(3);
	}
}
void *increament3(void *interval)
{
	int *interval3 = (int *)interval;
	while(1)
	{
		clk_t_3 += *interval3;
		printf("\nclk3 %d",clk_t_3);
		sleep(3);
	}
}
void *clk1(void *interval)
{
	int *interval1 = (int *)interval;
	pthread_t t;
	//printf("\nclk1 : %d",*interval1);
	pthread_create(&t,NULL,&increament1,(void *)interval1);
	sleep(5);
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&var);
		printf("\nrecived message to 1 at %d from %d",clk_t_1,sender);
		if(sender == 2)
		{
			if(clk_t_1<clk_t_2)
			{
				clk_t_1 = clk_t_2 + 1;
				printf("\nupdated clock to %d",clk_t_1);
			}
		}
		else if(sender == 3)
		{
			if(clk_t_1<clk_t_3)
				clk_t_1 = clk_t_3 + 1;
				printf("\nupdated clock to %d",clk_t_1);				
		}
		sleep(1);
		printf("\nmessage send from 1 at %d",clk_t_1);
		sender = 1;
		pthread_mutex_unlock(&var);
	}
}
void *clk2(void *interval)
{
	int *interval2 = (int *)interval;
	pthread_t t;
	//printf("\nclk2 : %d",*interval2);
	pthread_create(&t,NULL,&increament2,(void *)interval2);
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&var);
		printf("\nrecived message to 2 at %d from %d",clk_t_2,sender);
		if(sender == 1)
		{
			if(clk_t_2<clk_t_1)
			{
				clk_t_2 = clk_t_1 + 1;
				printf("\nupdated clock to %d",clk_t_2);
			}
		}
		else if(sender == 3)
		{
			if(clk_t_2<clk_t_3)
				clk_t_2 = clk_t_3 + 1;
				printf("\nupdated clock to %d",clk_t_2);				
		}
		sleep(1);
		printf("\nmessage send from 2 at %d",clk_t_2);
		sender = 2;
		pthread_mutex_unlock(&var);
		//sleep(1);
	}
}
void *clk3(void *interval)
{
	int *interval3 = (int *)interval;
	pthread_t t;
	//printf("\nclk3 : %d",*interval3);
	pthread_create(&t,NULL,&increament3,(void *)interval3);
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&var);
		printf("\nrecived message to 3 at %d from %d",clk_t_3,sender);
		if(sender == 2)
		{
			if(clk_t_3<clk_t_2)
			{
				clk_t_3 = clk_t_2 + 1;
				printf("\nupdated clock to %d",clk_t_3);
			}
		}
		else if(sender == 1)
		{
			if(clk_t_3<clk_t_1)
				clk_t_3 = clk_t_1 + 1;
				printf("\nupdated clock to %d",clk_t_3);				
		}
		sleep(1);
		printf("\nmessage send from 3 at %d",clk_t_3);
		sender = 3;
		pthread_mutex_unlock(&var);
		//sleep(1);
	}
}
void main()
{
	pthread_t arr[3];
	int interval1,interval2,interval3;
	interval1 = 3;
	interval2 = 5;
	interval3 = 7;
	pthread_create(&arr[0],0,&clk1,(void *)&interval1);
	pthread_create(&arr[1],0,&clk2,(void *)&interval2);
	pthread_create(&arr[2],0,&clk3,(void *)&interval3);
	
	pthread_join(arr[0],NULL);
	pthread_join(arr[1],NULL);
	pthread_join(arr[2],NULL);
}
