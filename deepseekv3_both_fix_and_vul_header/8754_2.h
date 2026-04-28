#include <stdlib.h>
#include <limits.h>

typedef struct _XDisplay Display;
typedef unsigned long XID;
typedef XID XserverRegion;

typedef struct {
    short x, y;
    unsigned short width, height;
} XRectangle;

typedef struct _XExtensionInfo {
    int major_opcode;
} XExtensionInfo;

typedef struct _XFixesExtDisplayInfo {
    XExtensionInfo *codes;
} XFixesExtDisplayInfo;

typedef struct {
    unsigned char reqType;
    unsigned char xfixesReqType;
    unsigned short length;
    XserverRegion region;
} xXFixesFetchRegionReq;

typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned int length;
    short x, y;
    unsigned short width, height;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
} xXFixesFetchRegionReply;

typedef struct {
    unsigned char type;
} xReply;

#define xFalse 0
#define X_XFixesFetchRegion 0
#define XFixesFetchRegion 0

void *Xmalloc(size_t size);
void _XEatDataWords(Display *dpy, unsigned long words);
void _XRead16(Display *dpy, short *data, long nbytes);
void _XEatData(Display *dpy, unsigned long bytes);
void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
XFixesExtDisplayInfo *XFixesFindDisplay(Display *dpy);
void XFixesCheckExtension(Display *dpy, XFixesExtDisplayInfo *info, void *ret);
void GetReq(int code, xXFixesFetchRegionReq *req);