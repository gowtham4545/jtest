#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include <string.h>

#define true 1
#define false 0

// extern unsigned long errs;

#define ASSERT(condition)                                                                                                           \
    do                                                                                                                              \
    {                                                                                                                               \
        if (!(condition))                                                                                                           \
        {                                                                                                                           \
            fprintf(stderr, "Assertion Failed: ( %s ), function %s, file %s, line %d\n", #condition, __func__, __FILE__, __LINE__); \
            printf("%s: abort ", __BASE_FILE__);                                                                                    \
            exit(EXIT_FAILURE);                                                                                                     \
        }                                                                                                                           \
    } while (0)

// Boolean Types
#define ASSERT_TRUE(val)     \
    do                       \
    {                        \
        ASSERT(val == true); \
    } while (0)

#define ASSERT_FALSE(val)     \
    do                        \
    {                         \
        ASSERT(val == false); \
    } while (0)

// Binary Types
#define ASSERT_EQ(value1, value2) \
    do                            \
    {                             \
        ASSERT(value1 == value2); \
    } while (0)

#define ASSERT_NE(value1, value2) \
    do                            \
    {                             \
        ASSERT(value1 != value2); \
    } while (0)

#define ASSERT_GT(value1, value2) \
    do                            \
    {                             \
        ASSERT(value1 > value2);  \
    } while (0)

#define ASSERT_GE(value1, value2) \
    do                            \
    {                             \
        ASSERT(value1 >= value2); \
    } while (0)

#define ASSERT_LT(value1, value2) \
    do                            \
    {                             \
        ASSERT(value1 < value2);  \
    } while (0)

#define ASSERT_LE(value1, value2) \
    do                            \
    {                             \
        ASSERT(value1 <= value2); \
    } while (0)

// String Types
#define ASSERT_STR_EQ(str1, str2)                                                                                                             \
    do                                                                                                                                        \
    {                                                                                                                                         \
        int n1 = strlen(str1);                                                                                                                \
        int n2 = strlen(str2);                                                                                                                \
        ASSERT_TRUE(n1 == n2);                                                                                                                \
        for (int i = 0; i < n1; i++)                                                                                                          \
        {                                                                                                                                     \
            if (str1[i] != str2[i])                                                                                                           \
            {                                                                                                                                 \
                fprintf(stderr, "Assertion Failed: ( %s != %s ), function %s, file %s, line %d\n", str1, str2, __func__, __FILE__, __LINE__); \
                printf("%s: abort ", __BASE_FILE__);                                                                                          \
                exit(EXIT_FAILURE);                                                                                                           \
            }                                                                                                                                 \
        }                                                                                                                                     \
    } while (0)

// Float Types