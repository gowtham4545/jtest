#include<stdlib.h>
#include<stdio.h>
#include"jtest/types.h"

int main(int argc, char const *argv[])
{
    system("echo Initialising Jtest...");
    system("echo Checking /test directory...");
    system("gcc -g .\\test\\*.c -o .\\output && .\\output ");
    printf("Total testcases: %d\n",tests);
    printf("Passed testcases: %d\n",tests-errno);

    return 0;
}
