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
	A a;

	// to create key
	key_t k_shareMem1 = ftok("firstShMem", 65);

	// create shared memory
	int ishmId = shmget(k_shareMem1, 5 * sizeof(A), IPC_CREAT | 0666);

	// to attached sharememory
	A *shmPtr = shmat(ishmId, (void *)0, 0);

	strcpy(a.stName, "Adarsh");
	a.iAge = 22;
	memcpy(&shmPtr[0], &a, sizeof(A));
	memset(&a, '\0', sizeof(A));

	strcpy(a.stName, "Ashish");
	a.iAge = 20;
	memcpy(&shmPtr[1], &a, sizeof(A));
	memset(&a, '\0', sizeof(A));

	strcpy(a.stName, "Sham");
	a.iAge = 52;
	memcpy(&shmPtr[2], &a, sizeof(A));
	memset(&a, '\0', sizeof(A));

	strcpy(a.stName, "Saroj");
	a.iAge = 32;
	memcpy(&shmPtr[3], &a, sizeof(A));
	memset(&a, '\0', sizeof(A));

	strcpy(a.stName, "Neha");
	a.iAge = 22;
	memcpy(&shmPtr[4], &a, sizeof(A));
	memset(&a, '\0', sizeof(A));

	return 0;
}
