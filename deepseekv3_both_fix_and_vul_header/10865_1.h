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

struct RegisterType {
    int Type;
};

extern void SWF_warn(const char *);
extern char *getName(struct RegisterType *);
extern char **pool;
extern int poolcounter;
extern struct RegisterType **regs;
extern size_t strlenext(const char *);
extern char *strcatext(char *, const char *);
extern char *strcpyext(char *, const char *);

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