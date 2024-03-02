#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <dirent.h>
#include <dlfcn.h>
#include <string.h>
#include <mach-o/dyld.h>
#include <mach-o/nlist.h>
#include "global.h"
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int *n;
char ***text;

void *load_module(const char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "Load Error: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    return handle;
}

void close_module(void *handle)
{
    dlclose(handle);
}

void run_functions(void *handle)
{
    // Define function pointer type
    typedef void (*FunctionType)();

    char strs[20][20] = {"add", "sub", "mul", "divide"};

    // Get function symbol
    void *symbol;
    // Cast the function symbol to the correct type
    dlerror();
    for (int i = 0; i < 4; i++)
    {
        // char s[20] = *text[i];
        symbol = dlsym(handle, strs[i]);
        int (*func)(int, int) = symbol;
        int r = func(5, 2);
        printf("Calling\n");
        printf("%d\n", r);
    }
    dlerror();
    perror("Hello");
    printf("%d\n", *n);
}

void main_loop(const char *directory_path)
{
    DIR *dir = opendir(directory_path);
    if (!dir)
    {
        perror("Loop Error");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".so") != NULL)
        {
            char module_path[256];
            sprintf(module_path, "%s/%s", directory_path, entry->d_name);
            void *handle = load_module(module_path);
            run_functions(handle);
            close_module(handle);
        }
    }

    closedir(dir);
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        printf("Format: %s testfile\n",argv[0]);
        exit(0);
    }
    size = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    n = shmat(size, (void *)0, 0);
    *n = 0;
    buffer = shmget(IPC_PRIVATE, sizeof(char) * 10000, IPC_CREAT | 0666);
    text = shmat(buffer, (void *)0, 0);
    char command[100];
    sprintf(command, "gcc -c -fPIC -o %s\b\b.o %s && gcc -shared -o %s\b\b.so %s\b\b.o",argv[1],argv[1],argv[1],argv[1]);
    // system("gcc -c -fPIC -o %s\b\b.o %s && gcc -shared -o %s\b\b.so %s\b\b.o");
    // system("gcc -c -fPIC -o b.o b.c && gcc -shared -o b.so b.o");
    // system(command);
    // printf("%s\n", command);
    const char *directory_path = "/Users/gos/Desktop/jtest/"; // Specify the directory containing the shared objects (.so files)
    main_loop(directory_path);
    return 0;
}