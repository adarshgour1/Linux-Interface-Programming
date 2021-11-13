#include <iostream>
#include <sys/time.h>

using namespace std;

/**
 * Here we will see how to formant a time variable time_h in diffrent format 
 */

int main()
{
    time_t *tv;
    time(tv);

    char *timeString = ctime(tv);   //Formated Output like: Sat Nov 13 17:18:10 2021
    cout << timeString;
    return 0;
}