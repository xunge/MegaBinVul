#include <stdlib.h>
#include <string.h>

#define PUSH_STRING 1
#define PUSH_CONSTANT 2
#define PUSH_CONSTANT16 3

struct SWF_ACTIONPUSHPARAM {
    int Type;
    union {
        char *String;
        int Constant8;
        int Constant16;
        int RegisterNumber;
    } p;
};

extern int poolcounter;
extern char **pool;
extern size_t strlenext(const char *str);
extern char *strcpyext(char *dest, const char *src);
extern void SWF_warn(const char *msg);
extern char *getString(struct SWF_ACTIONPUSHPARAM *act);