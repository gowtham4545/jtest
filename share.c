// #include <stdio.h>
// #include <stdlib.h>
// #include "global.h"
// #include <sys/ipc.h>
// #include <string.h>
// #include <sys/msg.h>

// #define QUEUE "array_queue"
// #define MAX_MESSAGE_SIZE sizeof(int) + 50

// typedef struct
// {
//     long mtype;
//     int index;
//     char data[20];
// } Message;

// void send_data(int index, char *data)
// {
//     printf("%d\n", index);
//     int queue_id = msgget(ftok(QUEUE, 1), 0666 | IPC_CREAT);
//     if (queue_id == -1)
//     {
//         perror("msgget failed");
//         exit(1);
//     }

//     Message message = {1, index, data};
//     if (msgsnd(queue_id, &message, MAX_MESSAGE_SIZE, 0) == -1)
//     {
//         perror("msgsnd failed");
//         exit(1);
//     }
// }

// void read_data()
// {
//     // ARRAY_SIZE = 6;÷
//     printf("Reading..\n");
//     int queue_id = msgget(ftok(QUEUE, 1), 0666);
//     if (queue_id == -1)
//     {
//         perror("msgget failed");
//         exit(1);
//     }
//     printf("Not Failed..\n");

//     Message message;
//     int data_received = 0;
//     char shared_array[ARRAY_SIZE][20];

//     while (data_received < 6)
//     {
//         if (msgrcv(queue_id, &message, MAX_MESSAGE_SIZE, 1, 0) == -1)
//         {
//             perror("msgrcv failed");
//             exit(1);
//         }

//         strcpy(shared_array[message.index], message.data);
//         data_received++;
//         printf("%s\n", shared_array[message.index]);
//     }

//     for (int i = 0; i < ARRAY_SIZE; i++)
//     {
//         printf("Reader: %s\n", shared_array[i]);
//     }

//     // Remember to remove the queue if needed
//     // msgctl(queue_id, IPC_RMID, NULL);
// }

// int main(int argc, char const *argv[])
// {
//     send_data(0, "kgjfgdg");
//     send_data(1, "kgjfgdg");
//     send_data(2, "kgjfgdg");
//     send_data(3, "kgjfgdg");
//     send_data(4, "kgjfgdg");
//     send_data(5, "kgjfgdg");
//     read_data();
//     printf("Exiting..");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <string.h>

#define ARRAY_SIZE 5
#define SHARED_MEMORY_NAME "shared_array"

typedef struct
{
    int size;
    char strings[ARRAY_SIZE][20];
} SharedArray;

void init_shared_memory(SharedArray **array)
{
    int shmid = shmget(IPC_CREAT, sizeof(SharedArray), 0666);
    if (shmid == -1)
    {
        perror("shmget failed");
        exit(1);
    }

    *array = (SharedArray *)shmat(shmid, NULL, 0);
    if (*array == (void *)-1)
    {
        perror("shmat failed");
        exit(1);
    }
}

void update_data(SharedArray *array)
{
    for (int i = 0; i < array->size; i++)
    {
        sprintf(array->strings[i], "Update %d", i);
    }
    array->size = ARRAY_SIZE;
}

int main()
{
    SharedArray *shared_array;
    init_shared_memory(&shared_array);

    // Update the shared array repeatedly
    for (int i = 0; i < 3; i++)
    {
        update_data(shared_array);
        printf("Writer: Updated data\n");
        // sleep(2); // Simulate delay
    }

    // Detach and clean up
    if (shmdt(shared_array) == -1)
    {
        perror("shmdt failed");
        exit(1);
    }

    shmctl(shmget(IPC_RMID, 0, 0), IPC_RMID, NULL);

    return 0;
}
