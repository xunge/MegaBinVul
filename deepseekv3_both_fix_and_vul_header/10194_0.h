#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAXDNAME 1024
#define DEF_LHS ""
#define DEF_RHS ""

struct hesiod_p {
    char *lhs;
    char *rhs;
};

static int cistrcmp(const char *s1, const char *s2);