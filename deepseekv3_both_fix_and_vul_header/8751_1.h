#include <stdlib.h>
#include <limits.h>

typedef struct _Display Display;
typedef struct {
    int max_keypermod;
    unsigned char *modifiermap;
} XModifierKeymap;

typedef struct {
    unsigned long length;
    int numKeyPerModifier;
} xGetModifierMappingReply;

typedef struct {
    int dummy;
} xReq;

typedef struct {
    int dummy; 
} xReply;

#define INT_MAX 2147483647
#define xFalse 0

#define LockDisplay(dpy) 
#define UnlockDisplay(dpy) 
#define SyncHandle() 
#define GetEmptyReq(func, req) 
#define _XReply(dpy, rep, n, b) 0
#define _XEatDataWords(dpy, n) 
#define _XReadPad(dpy, buf, n) 
#define Xmalloc(size) malloc(size)
#define Xfree(ptr) free(ptr)