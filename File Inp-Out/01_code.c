#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_LENTH 20
int main()

{
    int fd = open("File_01.txt",O_RDWR | O_CREAT | O_TRUNC);
    printf("Open file %d\n",fd);
    char buf[BUFFER_LENTH] = "1 2 3 4 5 6 7 8 9 10";

    int iByteWriten = write(fd,buf,BUFFER_LENTH);
    printf("No byte writen %d\n",iByteWriten);
    if(iByteWriten == -1)
    {
        puts("No Bytes Written to file");
    }
    close(fd);
    return 0;
}