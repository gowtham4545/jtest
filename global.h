#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/mman.h>

unsigned long errs;
short int pass;
short TEST_ABORT;

int size = 0;
int buffer;
char **buff;

// struct Word
// {
//     char str[20];
// };

// typedef struct SharedListNode
// {
//     char data[20];
//     struct SharedListNode *next;
// } SharedStringBuffer;

#define init(name)
// initFunc1((char *)name);

void initFunc()
{
    do
    {
        char *tt = malloc(sizeof(char) * strlen(__func__));
        buff = (char **)malloc(sizeof(char *) * (++size));
        buff[size - 1] = tt;
    } while (0);
}

void initFunc1(char *name)
{
    int *n = shmat(size, (void *)0, 0);
    char ***text = shmat(buffer, (void *)0, 0);
    *n = *n + 1;
    *text = realloc(*text, *n * sizeof(char[20]));
    *text[*n - 1] = name;
}

// ==================================================================

#define ARRAY_SIZE 10
struct Word *shared_array;

// // Program 1 (creator)
// void create_shared_array()
// {
//     int shmid = shmget(IPC_PRIVATE, sizeof(int) * ARRAY_SIZE, IPC_CREAT | 0666);
//     if (shmid == -1)
//     {
//         perror("shmget failed");
//         exit(1);
//     }

//     shared_array = (int *)shmat(shmid, NULL, 0);
//     if (shared_array == (void *)-1)
//     {
//         perror("shmat failed");
//         exit(1);
//     }
// }

// // Program 2 (attacher)
// void attach_to_shared_array()
// {
//     int shmid = shmget(IPC_PRIVATE, sizeof(int) * ARRAY_SIZE, 0);
//     if (shmid == -1)
//     {
//         perror("shmget failed");
//         exit(1);
//     }

//     shared_array = (int *)shmat(shmid, NULL, 0);
//     if (shared_array == (void *)-1)
//     {
//         perror("shmat failed");
//         exit(1);
//     }
// }