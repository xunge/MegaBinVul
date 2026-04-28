#include <limits.h>
#include <stdlib.h>

typedef struct _Display Display;
typedef struct xGetFontPathReply {
    unsigned int nPaths;
    unsigned int length;
} xGetFontPathReply;
typedef struct xReply xReply;
typedef struct xReq xReq;

#define _X_UNUSED
#define xFalse 0
#define GetFontPath 1
#define Xmalloc malloc
#define Xfree free

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void GetEmptyReq(int, xReq*);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
void _XEatDataWords(Display *dpy, unsigned long size);
void _XReadPad(Display *dpy, char *data, unsigned long size);
void SyncHandle(void);