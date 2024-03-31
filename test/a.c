#include<stdio.h>
#include"../types.h"

void f(){
    printf("f function\n");
    int a=0/1;
    // ASSERT_EQ(1,2);
}

void f1(){
    printf("f1 function\n");
    int a=0/1;
    ASSERT_EQ(1,1);
}

int main(int argc, char const *argv[])
{
    // printf("Main function\n");
    TEST_CASE("tcase","sample",f);
    TEST_CASE("tcase","sample1",f1);
    printf("testcases: %d\nerrors: %d\n",tests,errnos);
    return 0;
}
