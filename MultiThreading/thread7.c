#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutA = PTHREAD_MUTEX_INITIALIZER;
int glob = 0;

void *func1(void *args)
{
    while (1)
    {

        pthread_mutex_lock(&mutA);
        for (int i = 0; i < 10; i++)
        {
            glob++;
        }
        printf("func1: %d\n", glob);
        pthread_mutex_unlock(&mutA);
        sleep(1);
    }
}

void *func2(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&mutA);
        for (int i = 0; i < 10; i++)
        {
            glob++;
        }
        printf("func2: %d\n", glob);
        pthread_mutex_unlock(&mutA);
        sleep(1);
    }
}

int main()
{
    pthread_t a, b;
    pthread_create(&a, NULL, func1, NULL);
    pthread_create(&b, NULL, func2, NULL);

    pthread_exit(NULL);
    return 0;
}