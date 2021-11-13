#include <iostream>
#include <sys/time.h>

/**
 * When you required time in second and microsecond use timeval struct and gettime of the function
 */

int main()
{
    struct timeval varTime;
    gettimeofday(&varTime,NULL);

    printf("System time is %ld Second and %ld microSecond",varTime.tv_sec,varTime.tv_usec);
    return 0;
}
