#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func(void *var)
{
    sleep(2);
    puts("Inside a Thread");
    return NULL;
}

int main()
{
    pthread_t threadID;
    puts("Before Using a threading");

    pthread_create(&threadID,NULL,func,NULL);
    // pthread_join(threadID,NULL);
    puts("After calling a thread");

    pthread_exit(NULL);
    return 0;
}
