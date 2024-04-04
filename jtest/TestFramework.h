#ifndef _TESTFRAMEWORK_H
#define _TESTFRAMEWORK_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
typedef void (*test_function)();

typedef struct test_case_s
{
    const char *tname;
    test_function function;
    struct test_case_s *next;
} test_case_t;

test_case_t *tests;
static int tests_size = 0;
static int errnos = 0;
static int err_flag = 0;

void add_test(const char *name, test_function function)
{
    test_case_t *tcase = (test_case_t *)malloc(1 * sizeof(test_case_t));
    tcase->next = tests;
    tcase->tname = strdup(name);
    tcase->function = function;
    tests_size++;
    tests = tcase;
}

#define TEST(testcase)             \
    void testcase();               \
    add_test(#testcase, testcase); \
    void testcase()

void run_all_tests()
{
    if (!tests_size)
        return;
    test_case_t *tc = tests;

    printf("[==========] Running %d test cases.\n");
    printf("[----------] Global test environment set-up\n");
    time_t begin_t = time(NULL), start_t, end_t;
    while (tc != NULL)
    {
        printf("[ RUN      ] TC_%s\n", tc->tname);
        start_t = time(NULL);
        tc->function();
        end_t = time(NULL);
        if (!err_flag)
            printf("[       OK ] TC_%s (%lds)\n", tc->tname, (end_t - start_t));
        else
        {
            printf("[      ERR ] TC_%s (%lds)\n", tc->tname, (end_t - start_t));
            errno++;
            err_flag = !err_flag;
        }
        tc = tc->next;
    }
    end_t = time(NULL);
    printf("[==========] %d test cases ran. (%lds)\n", (end_t - begin_t));
    if (!errno)
        printf("[  PASSED  ] %d tests \n", tests_size);
    else
        printf("[  FAILED  ] %d tests from %d tests failed\n", errno, tests_size);
}

#endif