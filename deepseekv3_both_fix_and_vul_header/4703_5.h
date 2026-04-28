#include <stdlib.h>
#include <stddef.h>

typedef struct {
    void (*assertHeld)(void);
} Mutex;

static Mutex gFTMutex;
static int gFTCount = 0;
static void* gFTLibrary = NULL;

#define SkASSERT(cond) ((void)0)
#define SkDEBUGCODE(code) code
#define nullptr NULL
#define delete free(gFTLibrary);