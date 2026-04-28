#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _stack {
    int type;
    struct SWF_ACTIONPUSHPARAM *val;
    struct _stack *next;
};

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
    } p;
};

#define PUSH_STRING 1
#define DEBUG 1

extern struct _stack *Stack;
extern void SWF_warn(const char *);