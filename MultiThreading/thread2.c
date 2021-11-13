#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int gVar = 0;

void *func(void *a)
{
    int thid = *((int *)a);
    static int iStatVar = 0;

    gVar++ , iStatVar++;
    printf("loop no: %d, gVar = %d, iStatVar = %d\n",thid, gVar,iStatVar);
}

int main()
{
    pthread_t threadID;

    for (int  i = 0; i < 3; i++)
    {
        pthread_create(&threadID,NULL,func,(void *)&i);
        // pthread_join(threadID,NULL);
        usleep(1);
    }
    
    pthread_exit(NULL);
    return 0;
}