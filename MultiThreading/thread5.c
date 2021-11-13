#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct
{
    int first;
    int second;
}Num;

void *funcAdd(void *args)
{
    Num *p = (Num *)args;

    // Here we used dynamic memory allocation because when thread return pointer will point to stack variable which is deleted...
    int *ans = malloc(sizeof(int));
    *ans = p->first + p->second;

    return (void *)ans;
}

void *funcSub(void *args)
{
    Num *p = (Num *)args;

    int *ans = malloc(sizeof(int));
    *ans = p->first - p->second;

    return (void *)ans;
}

void *funcMul(void *args)
{
    Num *p = (Num *)args;

    int *ans = malloc(sizeof(int));
    *ans = p->first * p->second;

    return (void *)ans;
}


void *funcDiv(void *args)
{
    Num *p = (Num *)args;

    int *ans = malloc(sizeof(int));
    *ans = p->first / p->second;

    return (void *)ans;
}


int main()
{
    Num num;
    puts("Enter two numbers:");
    scanf("%d %d",&num.first,&num.second);

    //ans varibles pointer
    int *ansAdd, *ansSub, *ansMul, *ansDiv;
    //thread ids
    pthread_t t_Add, t_Sub, t_Mul, t_Div;
    pthread_create(&t_Add,NULL,funcAdd,(void *)&num);
    pthread_create(&t_Sub,NULL,funcSub,(void *)&num);
    pthread_create(&t_Mul,NULL,funcMul,(void *)&num);
    pthread_create(&t_Div,NULL,funcDiv,(void *)&num);

    pthread_join(t_Add,(void *)&ansAdd);
    pthread_join(t_Sub,(void *)&ansSub);
    pthread_join(t_Mul,(void *)&ansMul);
    pthread_join(t_Div,(void *)&ansDiv);


    puts("Answers:");
    printf("Sum: %d\n",*ansAdd);
    printf("Sub: %d\n",*ansSub);
    printf("Mul: %d\n",*ansMul);
    printf("Div: %d\n",*ansDiv);

    return 0;
}