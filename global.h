#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <setjmp.h>

static int tests = 0;
static int errnos = 0;
static int err_flag = 0;

// try-catch
jmp_buf exception_buffer;

#define TRY if (!setjmp(exception_buffer))
#define CATCH else

// test-case declaration

#define TEST_CASE(CASE, SUBCASE, func)                     \
    void wrapper_##func()                                  \
    {                                                      \
        printf("=============================\n");         \
        tests++;                                           \
        printf("Executing TC_%s.%s\n", CASE, SUBCASE);     \
        func();                                            \
        if (!err_flag)                                     \
        {                                                  \
            printf("[ PASSED ] %s : %s\n", CASE, SUBCASE); \
        }                                                  \
        else                                               \
        {                                                  \
            printf("[ FAILED ] %s : %s\n", CASE, SUBCASE); \
            errnos++;                                      \
        }                                                  \
        err_flag = 0;                                      \
        printf("=============================\n");         \
    }                                                      \
    wrapper_##func()

#endif