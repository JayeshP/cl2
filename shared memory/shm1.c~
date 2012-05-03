#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main()
{
	char *shmp;
	int shmid;
	key_t key;
	key =  2222;//1234 not worked
	shmid = shmget(234, 27, IPC_CREAT | 0666);   
	/*
		int shmget(key_t key, size_t size, int shmflg);
		0666 is the permission
	*/
	if(shmid ==-1)
		printf("\nerror in allocating shared memory");
		
	shmp = shmat(shmid,NULL,0);   
	/*
		void *shmat(int shmid, const void *shmaddr, int shmflg)
	*/
	if(shmp == (char *)-1)
		printf("\nerror in attaching shared memory segment to address space of the calling process");
		
	fgets(shmp,255,stdin);
	printf("\nsuccessfully written to shared memory");
}
