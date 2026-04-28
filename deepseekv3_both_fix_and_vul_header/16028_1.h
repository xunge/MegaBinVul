#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef long varnumber_T;
#define VARNUM_MIN LONG_MIN
#define VARNUM_MAX LONG_MAX
#define TRUE 1

bool in_vim9script(void);
void emsg(const char *msg);
const char e_divide_by_zero[] = "e_divide_by_zero";
const char *_(const char *str);