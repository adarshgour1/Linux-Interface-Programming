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
    fptr = fopen("Cfile.txt", "rb");

    fread((char *)&p, sizeof(p), sizeof(p), fptr);
    printf("id:[%d] name:[%s]\n", p.id, p.name);
    fclose(fptr);

    return 0;
}
