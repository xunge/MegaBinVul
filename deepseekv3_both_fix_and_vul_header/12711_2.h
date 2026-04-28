#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef struct _XDisplay Display;
typedef struct {
    unsigned short nFonts;
    unsigned int length;
} xSetFontPathReq;

#define safestrlen(s) strlen(s)
#define Xmalloc malloc
#define Xfree free
#define SetFontPath 1

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
void GetReq(int, xSetFontPathReq *);
void Data(Display *, char *, int);