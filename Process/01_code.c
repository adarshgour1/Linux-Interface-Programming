#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t processId, parentProcessId;
    processId = getpid();
    parentProcessId = getppid();
    puts("This is process Id is same which get from ps -ef command on terminal this is uniq identifier for process");
    printf("Process id:[%d]\n",processId);
    printf("Process id:[%d]\n",parentProcessId);
    system("ps -ef | grep 01_code | grep -v grep");  // this will execute linux command 
    return 0;
}