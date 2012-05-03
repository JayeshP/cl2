#define MAX 50
#include<stdio.h>
#include<stdlib.h>
int queue[MAX],total_process,status[MAX];
int ring(int gen)
{	
	int i,cnt=0,j,max;
	for(i=gen+1;i!=gen;i=(i%(total_process))+1)
	{
		
		if(status[i]==1)
		{
			//printf("\nmessage sent from %d to %d",i-1,i);
			printf("\n%d : %d ",i,cnt);
			queue[++cnt]=i;
			printf("queue[cnt]:  %d",queue[cnt]);
			/*printf("\nforwarded queue is : ");
			for(j=1;j<=cnt;j++)
			{
				printf("%d",queue[i]);	
			}*/
		}
	}
	queue[0]=gen;
	queue[cnt+1	]=gen;
	for(j=0;j<=cnt;j++)
	{
		printf("\nmessage sent from %d to %d",queue[j],queue[j+1]);
		printf("\nforwarded queue is : ");
		for(i=0;i<=j;i++)
			printf("%d",queue[i]);	
		
	}
	max = queue[0];
	for(j=1;j<cnt;j++)
	{
		if(max<queue[j])
			max = queue[j];
	}
	printf("\nNew co-ordinator is %d",max);
	for(j=0;j<cnt;j++)
	{
		printf("\nco-odinator message forwarded from %d to %d",queue[j],queue[j+1]);
	}	
	return max;
}
void main()
{
	int i,choice,n,crash,co_ordinator,active;
	printf("\nEnter number of processes : ");
	scanf("%d",&total_process);
	for(i=1;i<=total_process;i++)
	{
		status[i]=1;
		//ss[i]=0;
	}
	co_ordinator = total_process;
	do
	{	
		printf("\nRing Algorithm :\n1.crash process\n2.Activate process\n3Exit\n");	
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
					co_ordinator = ring(n);
					printf("\nNew co-ordinator is %d",co_ordinator);
				}
				break;
			case 2:
				printf("\nEnter the id of process to be Activated :");
				scanf("%d",&active);
				status[active]=1;
				if(co_ordinator<active)
				{
					printf("\nasking of co-ordinator message send from %d to %d",active,(active%total_process)+1);
					for(i=(active%total_process)+1;i!=active;i=(i%(total_process))+1)
					{		
						if(status[i]==1)
						{
							printf("\nasking of co-ordinator message send from %d to %d",i,(i%total_process)+1);
							if(co_ordinator==i)
							{
								printf("\nI am the co-ordinator send from %d to %d",i,active);
								break;
							}
						}
					}
				}
				break;
			case 3:
				exit(1);
				break;
		}
	}while(choice!=3);
}
	/*printf("\nNew co-ordinator %d selected ",active);
					for(i=1;i<active;i++)
					{
						//if(status[i]==1)
							printf("\nco-ordinator message send from %d process to %d process",active,i);
					}*/

