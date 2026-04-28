#include <stdlib.h>
#include <string.h>

#define PUSH_STRING 0
#define PUSH_CONSTANT 1
#define PUSH_CONSTANT16 2

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
        int Constant8;
        int Constant16;
        int RegisterNumber;
    } p;
};

extern void SWF_warn(const char *);
extern char *getString(struct SWF_ACTIONPUSHPARAM *);
extern char *strcpyext(char *, const char *);
extern size_t strlenext(const char *);
extern char **pool;
extern int poolcounter;