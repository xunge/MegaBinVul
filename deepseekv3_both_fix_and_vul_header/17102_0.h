#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
        int RegisterNumber;
        int Boolean;
        double Double;
        long Integer;
        int Constant8;
        int Constant16;
    } p;
};

extern int poolcounter;
extern char **pool;
extern struct SWF_ACTIONPUSHPARAM **regs;
extern size_t strlenext(const char *s);
extern char *strcatext(char *dest, const char *src);
extern char *strcpyext(char *dest, const char *src);
extern char *getName(struct SWF_ACTIONPUSHPARAM *act);
extern void SWF_warn(const char *msg);

enum {
    PUSH_STRING,
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