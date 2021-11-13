#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

typedef struct
{
	char stName[20];
	int iAge;
} A;

int main()
{

	// to create key
	key_t k_shareMem1 = ftok("firstShMem", 65);

	// create shared memory
	int ishmId = shmget(k_shareMem1,2*sizeof(A),IPC_CREAT | 0666);

	// to attached sharememory
	A *shmPtr = shmat(ishmId,(void *)0, 0);

    for (int i = 0; i < 2; i++)
    {
       printf("%d stName:[%s] iAge:[%d]\n",i,shmPtr[i].stName,shmPtr[i].iAge);
    }
    
    shmctl(ishmId,IPC_RMID,NULL);
	return 0;
}
