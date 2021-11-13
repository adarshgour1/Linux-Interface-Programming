// how pass argument to thread and how take return from it

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct 
{
    int real;
    int com;
}ComplexNum;

void *sumOfCoplexNum(void *arg)
{
    ComplexNum *p = (ComplexNum *)arg;
    ComplexNum *ans = malloc(sizeof(ComplexNum));
    ans->real = 0, ans->com = 0;

    printf("value in ans real: [%d] com: [%d]\n\n",ans->real,ans->com);
    for (int i = 0; i < 10; i++)
    {
        printf("value to add real: [%d] com: [%d]\n",p[i].real,p[i].com);
        ans->real += p[i].real;
        ans->com += p[i].com;
    }
    
    return (void *)ans;
}
int main()
{
    //declaring array
    ComplexNum sComNum[10];
    ComplexNum *result;

    //assigning values
    for (int i = 0; i < 10; i++)
    {
        sComNum[i].real = 1;
        sComNum[i].com = 1;
    }
    
    pthread_t tId;
    pthread_create(&tId,NULL,sumOfCoplexNum,(void *)sComNum);

    // join will attach thread and force next execution until it return val
    pthread_join(tId,(void *)&result);  // **IMP** Here we pass address of pointer not pointer itself

    puts("");
    printf("Ans: %d + j%d\n",result->real,result->com);


    return 0;
}