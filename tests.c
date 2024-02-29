#include "types.h"

int some_function_to_test()
{
    return 1;
}

void test_example()
{
    // Arrange (setup)
    int result = some_function_to_test();

    // Act (perform the test)
    ASSERT_FALSE((!result));

    // Assert (verify the result)
    printf("Test Passed: example_test\n");
}

void test_add(int a, int b)
{
    ;
    ASSERT_EQ(1 + 2, 4);
    printf("Test Passed: Add function\n");
}