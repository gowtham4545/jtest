#include<stdlib.h>
#include"jtest/types.h"

int main(int argc, char const *argv[])
{
    system("echo Initialising Jtest...");
    system("echo Checking /test directory...");
    run_all_tests();

    return 0;
}
