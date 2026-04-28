#include <stdio.h>
#include <stdlib.h>

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
        float Float;
        int RegisterNumber;
        int Boolean;
        double Double;
        long Integer;
        int Constant8;
        int Constant16;
    } p;
};

extern char *regs[];
extern char *getName(struct SWF_ACTIONPUSHPARAM *act);
extern char *getString(struct SWF_ACTIONPUSHPARAM *act);

enum {
    PUSH_STRING,
    PUSH_FLOAT,
    PUSH_NULL,
    PUSH_UNDEF,
    PUSH_REGISTER,
    PUSH_BOOLEAN,
    PUSH_DOUBLE,
    PUSH_INT,
    PUSH_CONSTANT,
    PUSH_CONSTANT16,
    PUSH_VARIABLE
};