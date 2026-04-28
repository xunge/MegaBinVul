#include <stdlib.h>
#include <string.h>

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
        int Constant8;
        int Constant16;
        int RegisterNumber;
    } p;
};

#define PUSH_STRING 0
#define PUSH_CONSTANT 1
#define PUSH_CONSTANT16 2

extern void SWF_warn(const char *);
extern char *pool[];
extern int poolcounter;
extern char *getString(struct SWF_ACTIONPUSHPARAM *);
extern char *strcpyext(char *, const char *);
extern size_t strlenext(const char *);