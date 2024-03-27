#include <stdio.h>
#include <string.h>
// #include <errno.h>
#include <stdlib.h>
// #include "global.h"

// void hi()
// {
//     FILE *f = fopen(".c", "r");
//     init(__func__);
// }

int main(int argc, char const *argv[])
{
    // hi();
    // printf("%d\n", errno);

    // perror
    char *b = "ghfj";
    char *a = malloc(strlen(b) + 4); // Allocating memory for a
    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    sprintf(a, "%s Hi\n", b);
    printf("%s\n", a);
    free(a); // Freeing allocated memory
    return 0;
}
