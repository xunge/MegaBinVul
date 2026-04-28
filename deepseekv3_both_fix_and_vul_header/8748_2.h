#include <stdlib.h>
#include <string.h>

typedef unsigned long VisualID;
typedef unsigned long Window;

typedef struct {
    int type;
    int base_id;
    int num_ports;
    int num_formats;
    int num_adaptors;
    char *name;
    struct XvFormat *formats;
} XvAdaptorInfo;

typedef struct XvFormat {
    int depth;
    VisualID visual_id;
} XvFormat;

typedef struct {
    unsigned char reqType;
    unsigned char xvReqType;
    unsigned short length;
    unsigned long window;
} xvQueryAdaptorsReq;

typedef struct {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned long length;
    unsigned long num_adaptors;
    unsigned long pad1;
    unsigned long pad2;
    unsigned long pad3;
    unsigned long pad4;
} xvQueryAdaptorsReply;

typedef struct {
    unsigned long type;
    unsigned long base_id;
    unsigned long num_ports;
    unsigned long num_formats;
    unsigned long name_size;
} xvAdaptorInfo;

typedef struct {
    unsigned long depth;
    unsigned long visual;
} xvFormat;

typedef struct _XDisplay Display;
typedef struct _XExtDisplayInfo XExtDisplayInfo;
typedef struct _xReply xReply;

#define QueryAdaptors 1
#define sz_xvAdaptorInfo (5 * 4)
#define sz_xvFormat (2 * 4)
#define pad_to_int32(n) (((n) + 3) & ~3)

#define XvBadExtension 1
#define XvBadReply 2
#define XvBadAlloc 3
#define Success 0
#define xFalse 0

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
XExtDisplayInfo* xv_find_display(Display *dpy);
void XvCheckExtension(Display *dpy, XExtDisplayInfo *info, int err);
void XvGetReq(int reqType, void *req);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
void _XEatDataWords(Display *dpy, unsigned long count);
void _XRead(Display *dpy, char *buf, long size);
void* Xmalloc(size_t size);
void Xfree(void *ptr);
void XvFreeAdaptorInfo(XvAdaptorInfo *info);