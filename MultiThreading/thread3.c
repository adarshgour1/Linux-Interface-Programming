// this code will explain how to create thread 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myTurn(void *args)
{
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        puts("My Turn...");
    }
    return NULL;
}

void *yourTurn(void *args)
{
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        puts("Your Turn...");
    }
    return NULL;
}
int main()
{
    pthread_t tId;
    pthread_create(&tId, NULL, myTurn, NULL);
    yourTurn(NULL);

    pthread_exit(NULL);         //wait until all thread complete thier execution
    return 0;
}