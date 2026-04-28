#include <stdio.h>

struct SWF_ACTIONPUSHPARAM;
extern struct SWF_ACTIONPUSHPARAM *peek();
extern struct {
    char type;
    void *val;
    struct {
        char type;
        void *val;
    } *next;
} *Stack;