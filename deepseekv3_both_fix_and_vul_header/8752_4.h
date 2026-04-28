#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef struct _XDisplay Display;
typedef unsigned long XID;
typedef XID Drawable;
typedef XID Colormap;
typedef int Bool;
#define False 0
#define True 1
#define _Xconst const
#define xFalse False

typedef struct {
    unsigned char type;
    unsigned char detail;
    unsigned short sequence_number;
} xReply;

typedef struct {
    int nFonts;
    unsigned int length;
} xListFontsReply;

typedef struct {
    unsigned char reqType;
    unsigned char pad;
    unsigned short length;
    unsigned int maxNames;
    unsigned int nbytes;
} xListFontsReq;

#define LockDisplay(d)
#define UnlockDisplay(d)
#define SyncHandle()
#define GetReq(name, req) req = (xListFontsReq*)malloc(sizeof(xListFontsReq))
#define _XSend(d, p, n)
#define _XReply(d, r, n, b) 1
#define _XEatDataWords(d, n)
#define _XReadPad(d, p, n)
#define Xmalloc(s) malloc(s)
#define Xfree(p) free(p)