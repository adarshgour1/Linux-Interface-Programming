#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//global variable
int globvar = 0;
pthread_cond_t condA = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutxA = PTHREAD_MUTEX_INITIALIZER;

void *mul_table_func(void *args)
{
    while (1)
    {
        
        pthread_mutex_lock(&mutxA);
        pthread_cond_wait(&condA, &mutxA);
        pthread_mutex_unlock(&mutxA);
        int temp = globvar;

        puts("");
        puts("-------------------------------------");
        for (int i = 1; i <= 10; i++)
        {
            printf("%d\tx\t%d\t=\t%d\n", temp, i, temp * i);
        }
        puts("-------------------------------------");
    }
    return NULL;
}

void *intput_taker(void *args)
{
    while (1)
    {
        printf("Enter a num:\n");
        scanf("%d", &globvar);
        pthread_mutex_lock(&mutxA);
        pthread_cond_broadcast(&condA);
        pthread_mutex_unlock(&mutxA);

        usleep(1); //just for output formating nothing to do with threads
    }
    return NULL;
}

int main()
{
    pthread_t a, b;
    setvbuf(stdout, NULL, _IONBF, 0);
    pthread_create(&b, NULL, intput_taker, NULL);
    pthread_create(&a, NULL, mul_table_func, NULL);

    pthread_exit(NULL);
    return 0;
}