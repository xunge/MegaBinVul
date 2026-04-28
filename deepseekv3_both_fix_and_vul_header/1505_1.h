#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {
    int language;
    union {
        struct {
            char *body;
        } s;
    } data;
} procinfo;

typedef void* ADDRESS;

extern char *omStrDup(const char *s);
extern void omFree(ADDRESS p);
extern void *omAlloc(size_t size);
extern void Print(const char *fmt, ...);
extern void PrintS(const char *s);
extern void iiGetLibProcBuffer(procinfo *pi);
extern void si_unlink(const char *filename);
extern void si_wait(int *pid);
extern size_t myfread(void *ptr, size_t size, size_t nmemb, FILE *stream);

#define LANG_SINGULAR 0