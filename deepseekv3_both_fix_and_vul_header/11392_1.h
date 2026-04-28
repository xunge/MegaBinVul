#include <limits.h>
#include <stdlib.h>

#define _X_UNUSED
#define xFalse 0
#define INT_MAX 2147483647

typedef struct _XDisplay Display;
typedef struct _XReply xReply;
typedef struct _xReq xReq;

typedef struct {
    unsigned long length;
    unsigned long nExtensions;
} xListExtensionsReply;

#define ListExtensions 0
#define Xmalloc malloc
#define Xfree free

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
void GetEmptyReq(int, xReq*);
int _XReply(Display*, xReply*, int, int);
void _XReadPad(Display*, char*, unsigned long);
void _XEatDataWords(Display*, unsigned long);