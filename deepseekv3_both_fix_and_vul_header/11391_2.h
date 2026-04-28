#include <limits.h>
#include <stdlib.h>

typedef struct _XDisplay Display;
typedef struct {
    int nPaths;
    unsigned int length;
} xGetFontPathReply;
typedef struct {
    int dummy;
} xReply;
typedef struct {
    int dummy;
} xReq;

#define _X_UNUSED
#define xFalse 0
#define GetFontPath 1
#define Xmalloc malloc
#define Xfree free

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void GetEmptyReq(int code, xReq *req);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
void _XEatDataWords(Display *dpy, unsigned long count);
void _XReadPad(Display *dpy, char *data, unsigned long count);
void SyncHandle(void);