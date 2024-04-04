#include<stdio.h>
#include"../jtest/types.h"

TEST(f){
    printf("f function\n");
    int a=0/1;
    ASSERT_EQ(1,2);
}

TEST(f1){
    printf("f1 function\n");
    int a=0/1;
    ASSERT_EQ(1,1);
}
