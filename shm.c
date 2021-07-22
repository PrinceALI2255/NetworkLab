#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/ipc.h>

int main()
{
    int val,*shmptr, shmid;

    printf("\nEnter the value: ");
    scanf("%d",&val);

    shmid=shmget(2446,2,IPC_CREAT|0666);
    shmptr=shmat(shmid,NULL,0);

    int f1=fork();
    
    if(f1>0)
    {
        //Parent Process
        *shmptr=val;
        printf("Parent Process value = %d\n", *shmptr);
    }
    else
    {
        //Child Process
        val=val*val;
        *shmptr=val;
        printf("Child Process value = %d\n", *shmptr);
    }

    shmdt(shmptr);

}
