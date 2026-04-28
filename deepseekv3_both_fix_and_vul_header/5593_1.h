#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#define SSCANF sscanf
#define L(s) s

typedef char CHAR;

extern const char *str_double[4];
extern const double val_double[24];
extern const char *str_long[4];
extern const char *fmt_long[4];
extern const long val_long[6];

struct test_case {
    const char *str;
    const char *fmt;
    int retval;
};

struct test_case int_tests[] = {};
struct test_case double_tests[] = {};

struct test_case2 {
    const char *str;
    const char *fmt;
    int retval;
    char residual;
};

struct test_case2 double_tests2[] = {};