#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "global.h"

void hi()
{
    FILE *f = fopen(".c", "r");
    init(__func__);
}

int main(int argc, char const *argv[])
{
    // hi();
    // printf("%d\n", errno);

    // perror("Error");
    const char t[10] = {'h', 'i', ' ', 'h', 'e', '\b', '\b', 'l', 'l'};
    printf("%s\b\bll\n", __func__);
    return 0;
}
