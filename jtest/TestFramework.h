#ifndef _TESTFRAMEWORK_H
#define _TESTFRAMEWORK_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef void (*test_function)();

typedef struct test_case_s
{
    const char *tname;
    test_function function;
    test_case_s *next;
} test_case_t;

test_case_t *tests;
static int tests_size = 0;

void add_test(const char *name, test_function function)
{
    test_case_t *tcase = (test_case_t *)malloc(1 * sizeof(test_case_t));
    tcase->next = tests;
    tcase->tname = strdup(name);
    tcase->function = function;
    tests_size++;
    tests = tcase;
}

void run_all_tests()
{
    if (!tests_size)
        return;
    test_case_t *tc = tests;

    while (tc != NULL)
    {
        printf("[ RUN       ] %s\n",tc->tname);
    }
}

#endif