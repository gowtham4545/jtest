#include <stdlib.h>
#include <stdio.h>
#include "jtest/types.h"

int main(int argc, char const *argv[])
{
    system("echo Initialising Jtest...");
    system("echo Checking /test directory...");
    system("gcc -g .\\test\\*.c -o .\\output && .\\output ");
    run_all_tests();
    return 0;
}
