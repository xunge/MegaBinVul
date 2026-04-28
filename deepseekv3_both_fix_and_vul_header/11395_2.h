#include <stdlib.h>
#include <limits.h>

#define ListExtensions 0
#define _X_UNUSED
#define xFalse 0
#define Xmalloc malloc
#define Xfree free

typedef struct _XDisplay Display;
typedef struct {
    unsigned long length;
    unsigned long nExtensions;
} xListExtensionsReply;
typedef struct {
    unsigned char reqType;
    unsigned char pad;
    unsigned short length;
    unsigned long unused;
} xReq;
typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
} xReply;

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
void GetEmptyReq(int, xReq*);
int _XReply(Display*, xReply*, int, int);
void _XEatDataWords(Display*, unsigned long);
void _XReadPad(Display*, char*, unsigned long);