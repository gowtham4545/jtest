#include<stdlib.h>

int main(int argc, char const *argv[])
{
    system("echo Initialising Jtest...");
    system("echo Checking /test directory...");
    system("mkdir obj && gcc -g ./test/*.c -o ./obj/output && ./obj/output ");
    system("rm -rf ./obj");

    return 0;
}
