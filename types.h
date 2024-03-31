#ifndef _TYPES_H
#define _TYPES_H

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
            printf("%s: abort \n", __BASE_FILE__);                                                                                    \
            err_flag = true;                                                                                                        \
            return;                                                                                                                 \
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
#define ASSERT_STR_EQ(str1, str2)             \
    do                                        \
    {                                         \
        int n1 = strlen(str1);                \
        int n2 = strlen(str2);                \
        ASSERT_TRUE(n1 == n2);                \
        ASSERT_TRUE(strcmp(str1, str2) == 0); \
    } while (0)

#define ASSERT_STR_NE(str1, str2)              \
    do                                         \
    {                                          \
        ASSERT_FALSE(strcmp(str1, str2) == 0); \
    } while (0)

#define ASSERT_STR_CASE_EQ(str1, str2)            \
    do                                            \
    {                                             \
        ASSERT_TRUE(strcasecmp(str1, str2) == 0); \
    } while (0)

#define ASSERT_STR_CASE_NE(str1, str2)             \
    do                                             \
    {                                              \
        ASSERT_FALSE(strcasecmp(str1, str2) == 0); \
    } while (0)

// Float Types

#define ASSERT_NEAR(val1, val2, d)                             \
    do                                                         \
    {                                                          \
        ASSERT_TRUE((val1 - val2 <= d) || (val2 - val1 <= d)); \
    } while (0)

// Exception Types
#define ASSERT_THROW(func, err)

#define ASSERT_THROW_ANY(func)

#define ASSERT_NO_THROW(func)

#endif