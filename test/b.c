#include"../jtest/types.h"

void f2(){
    return ;
}

int main(int argc, char const *argv[])
{
    TEST_CASE("testcase2","add_func",f2);
    return 0;
}
