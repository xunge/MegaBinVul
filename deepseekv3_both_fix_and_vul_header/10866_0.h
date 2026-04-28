#include <stdlib.h>
#include <string.h>

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
        unsigned int Constant8;
        unsigned int Constant16;
        unsigned int RegisterNumber;
    } p;
};

extern char *pool[];
extern unsigned int poolcounter;
extern void SWF_warn(const char *);
extern size_t strlenext(const char *);
extern char *strcpyext(char *, const char *);
extern char *getString(struct SWF_ACTIONPUSHPARAM *);

#define PUSH_STRING 0
#define PUSH_CONSTANT 1
#define PUSH_CONSTANT16 2