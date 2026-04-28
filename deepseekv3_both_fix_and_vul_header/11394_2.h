#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct _XDisplay Display;
typedef unsigned long XID;
typedef XID Window;
typedef unsigned char Bool;
#define xFalse 0
#define _Xconst const

typedef struct {
    unsigned long nFonts;
    unsigned long length;
} xListFontsReply;

typedef struct {
    int maxNames;
    long nbytes;
    unsigned long length;
} xListFontsReq;

typedef struct {
    unsigned char type;
} xReply;

#define GetReq(name, req) \
    req = (xListFontsReq *) malloc(sizeof(xListFontsReq)); \
    if (!req) { \
        *actualCount = 0; \
        return (char **) NULL; \
    }

#define LockDisplay(dpy) 
#define UnlockDisplay(dpy) 
#define SyncHandle() 

void _XSend(Display *dpy, const char *pattern, long nbytes);
Bool _XReply(Display *dpy, void *rep, int extra, Bool discard);
void _XEatDataWords(Display *dpy, unsigned long length);
void _XReadPad(Display *dpy, char *ch, unsigned long rlen);

void *Xmalloc(size_t size);
void Xfree(void *ptr);