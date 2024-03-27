#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char **t = {"hello", "hi", "morning"};
    printf("%s\n", t++);
    printf("%s\n", t++);
    printf("%s\n", t++);
    return 0;
}
