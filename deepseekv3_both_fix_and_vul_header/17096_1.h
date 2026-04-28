#include <stdio.h>

#define PUSH_FLOAT 0
#define PUSH_NULL 1
#define PUSH_REGISTER 2
#define PUSH_DOUBLE 3
#define PUSH_INT 4

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        float Float;
        int RegisterNumber;
        double Double;
        int Integer;
    } p;
};

extern struct SWF_ACTIONPUSHPARAM *regs[];