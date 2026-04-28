#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct _Display Display;
typedef unsigned long CARD32;
typedef unsigned short CARD16;
typedef int Bool;
#define xFalse 0

typedef struct {
    int nFonts;
    unsigned long length;
} xListFontsReply;

typedef struct {
    int maxNames;
    CARD16 nbytes;
    unsigned long length;
} xListFontsReq;

typedef struct {
    unsigned char type;
} xReply;

#define LockDisplay(dpy) 
#define UnlockDisplay(dpy) 
#define SyncHandle() 
#define GetReq(op, req) 
#define _XSend(dpy, data, len) 
#define _XReply(dpy, rep, extra, discard) 0
#define _XEatDataWords(dpy, len) 
#define _XReadPad(dpy, buf, len) 
#define Xmalloc(size) malloc(size)
#define Xfree(ptr) free(ptr)
#define Xmallocarray(n, size) malloc((n) * (size))
#define _Xconst const