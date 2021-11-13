#include <stdio.h>
#include <string.h>

struct Person
{
    int id;
    char name[20];
} p;

int main()
{
    FILE *fptr;
    fptr = fopen("Cfile.txt", "wb");

    p.id = 23;
    strcpy(p.name, "Adarsh");

    fwrite((char *)&p, sizeof(p), sizeof(p), fptr);
    fclose(fptr);

    return 0;
}
