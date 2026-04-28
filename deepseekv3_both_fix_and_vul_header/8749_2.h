#include <stdlib.h>
#include <string.h>

typedef struct _Display Display;
typedef unsigned long XvPortID;

typedef struct {
    int numerator;
    int denominator;
} XvRational;

typedef struct {
    XvPortID encoding_id;
    unsigned int width;
    unsigned int height;
    XvRational rate;
    char *name;
    unsigned int num_encodings;
} XvEncodingInfo;

typedef struct {
    unsigned short length;
    unsigned short num_encodings;
} xvQueryEncodingsReply;

typedef struct {
    unsigned char reqType;
    unsigned char xvReqType;
    unsigned short length;
    XvPortID port;
} xvQueryEncodingsReq;

typedef struct {
    unsigned int encoding;
    unsigned short width;
    unsigned short height;
    XvRational rate;
    unsigned short name_size;
} xvEncodingInfo;

typedef struct {
    unsigned char type;
    unsigned char data[31];
} xReply;

typedef struct XExtDisplayInfo XExtDisplayInfo;

#define XvBadExtension 1
#define XvBadReply 2
#define XvBadAlloc 3
#define Success 0
#define xFalse 0
#define sz_xvEncodingInfo (sizeof(xvEncodingInfo))
#define QueryEncodings 1

#define Xmalloc malloc
#define Xfree free

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
void _XEatDataWords(Display *dpy, unsigned long count);
void _XRead(Display *dpy, char *data, long size);
XExtDisplayInfo *xv_find_display(Display *dpy);
void XvCheckExtension(Display *dpy, XExtDisplayInfo *info, int error);
void XvGetReq(int request, xvQueryEncodingsReq *req);
void XvFreeEncodingInfo(XvEncodingInfo *info);
int pad_to_int32(int size);