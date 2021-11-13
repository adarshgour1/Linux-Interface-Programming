#include <iostream>
#include <sys/time.h>

using namespace std;

// When you required time only in second use time_t 
// this contain a same value that is present in timeval tv_sec filed.

int main()
{
    time_t varTime;

    time(&varTime);
    cout << "Value of varTime is " << varTime << endl;
    return 0;
}