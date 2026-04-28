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

#define PUSH_STRING 0
#define PUSH_NULL 1
#define PUSH_UNDEF 2
#define PUSH_REGISTER 3
#define PUSH_BOOLEAN 4
#define PUSH_DOUBLE 5
#define PUSH_INT 6
#define PUSH_CONSTANT 7
#define PUSH_CONSTANT16 8
#define PUSH_VARIABLE 9
#define DEBUG 1