#include<stdio.h>
#include"../types.h"

void f(){
    printf("f function\n");
    int a=0/1;
    ASSERT_EQ(1,2);
}

void f1(){
    printf("f1 function\n");
    int a=0/1;
    ASSERT_EQ(1,1);
}

int main(int argc, char const *argv[])
{
    TEST_CASE("tcase","sample",f);
    TEST_CASE("tcase","sample1",f1);
    return 0;
}
