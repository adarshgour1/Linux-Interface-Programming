#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_LENTH 20
#define OFFSET 5
int main()

{
    int fd = open("File_01.txt", O_RDONLY);
    printf("Open file fd:[%d]\n", fd);
    char buf[BUFFER_LENTH] = {};

    lseek(fd, OFFSET, SEEK_SET);
    for (int i = 0; i < BUFFER_LENTH; i++)
    {
        int iByteRead = read(fd, buf, 1);
        if(strcmp(buf,"5") == 0){
            lseek(fd,OFFSET,SEEK_CUR);
        }
        printf("[%s] ",buf);
    }
    puts("");


    close(fd);
    return 0;
}