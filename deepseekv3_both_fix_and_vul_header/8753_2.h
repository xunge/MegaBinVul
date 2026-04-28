#include <limits.h>
#include <stdlib.h>

typedef struct _XDisplay Display;
typedef int Bool;
#define xFalse 0

typedef struct {
    int nExtensions;
    unsigned long length;
} xListExtensionsReply;

typedef struct {
    int dummy;
} xReq;

typedef struct {
    int dummy;
} xReply;

#define ListExtensions 0

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
void _XReadPad(Display *dpy, char *data, unsigned long length);
void _XEatDataWords(Display *dpy, unsigned long length);
Bool _XReply(Display *dpy, xReply *rep, int extra, Bool discard);
void GetEmptyReq(int type, xReq *req);

void *Xmalloc(size_t size);
void Xfree(void *ptr);