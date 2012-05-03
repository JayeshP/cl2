#include<stdio.h>
#define MAX_PROCESS 50
#include<stdlib.h>
int status[MAX_PROCESS]; //keep track of activated process..0 for crashed and 1 for active
int total_process;
int ss[MAX_PROCESS];
int bully1(int place )
{
	int i,flag=0;
	for(i=place+1;i<=total_process;i++)
	{
		printf("\nmessage send from %d to %d",place,i);
		
	}
	for(i=place+1;i<=total_process;i++)
		if(status[i]==1)
		{
			printf("\ntakeover message sent from %d",i);
			//ss[i]=1;
			flag=1;
		}
	
	/*else
	{
		printf("new co-ordinator is %d",place);
		return;
	}*/
	return place;
}
int bully(int place)
{
	int i,n;
	for(i=place;i<=total_process && status[i]==1;i++)
		{
			printf("\nElection algorithm start by %d process",i);
			n = bully1(i);	
		}
		return n;
}
void main()
{
	int i,choice,n,crash,co_ordinator,active;
	printf("\nEnter number of processes : ");
	scanf("%d",&total_process);
	for(i=1;i<=total_process;i++)
	{
		status[i]=1;
		ss[i]=0;
	}
	co_ordinator = total_process;
	do
	{	
		printf("\nBully Algorithm :\n1.crash process\n2.Activate process\n3Exit\n");	
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the id of process to be crashed :");
				scanf("%d",&crash);
				status[crash]=0;
				if(co_ordinator==crash)
				{
					printf("\nEnter the generator id of process : ");
					scanf("%d",&n);
					co_ordinator = bully(n);
					printf("\nNew co-ordinator is %d",co_ordinator);
				}
				break;
			case 2:
				printf("\nEnter the id of process to be Activated :");
				scanf("%d",&active);
				if(co_ordinator<active)
				{
					printf("\nNew co-ordinator %d selected ",active);
					for(i=1;i<active;i++)
					{
						//if(status[i]==1)
							printf("\nco-ordinator message send from %d process to %d process",active,i);
					}
				}
				break;
			case 3:
				exit(1);
				break;
		}
	}while(choice!=3);
}


