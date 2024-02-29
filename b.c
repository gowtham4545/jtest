#include <stdio.h>
#include "global.h"
__attribute__((visibility("default")));

int add(int a, int b)
{
    init(__func__);
    return a + b;
}

int sub(int a, int b)
{
    init(__func__);
    return a - b;
}

int mul(int a, int b)
{
    init(__func__);
    return a * b;
}

int divide(int a, int b)
{
    init(__func__);
    return a / b;
}

int main(int argc, char const *argv[])
{
    // init();
    add(1, 2);
    return 0;
}
