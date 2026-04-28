#include <limits.h>
#include <stdlib.h>

typedef unsigned long Drawable;
typedef struct _XImage {
    int depth;
    int height;
    int bytes_per_line;
} XImage;

struct _Display {
    int bitmap_pad;
};

typedef struct _Display Display;

#define INT_MAX __INT_MAX__
#define xFalse 0
#define XYPixmap 1
#define ZPixmap 2

struct xGetImageReply {
    unsigned long length;
    unsigned long visual;
    unsigned int depth;
};

struct xGetImageReq {
    Drawable drawable;
    int x;
    int y;
    unsigned int width;
    unsigned int height;
    unsigned long planeMask;
    int format;
};

typedef struct xGetImageReply xGetImageReply;
typedef struct xGetImageReq xGetImageReq;

#define GetReq(a, b) ((b) = malloc(sizeof(xGetImageReq)))
#define LockDisplay(d)
#define UnlockDisplay(d)
#define SyncHandle()
#define _XReply(d, r, n, b) 1
#define _XEatDataWords(d, l)
#define _XReadPad(d, p, n)
#define _XVIDtoVisual(d, v) (v)
#define _XGetScanlinePad(d, b) 32
#define Xmalloc(s) malloc(s)
#define Xfree(p) free(p)
#define XDestroyImage(i) free(i)
#define Ones(m) __builtin_popcount(m)

XImage *XCreateImage(Display *dpy, unsigned long visual, unsigned int depth, 
                    int format, int offset, char *data, 
                    unsigned int width, unsigned int height, 
                    int bitmap_pad, int bytes_per_line);