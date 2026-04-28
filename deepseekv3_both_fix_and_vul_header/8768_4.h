#include <stddef.h>
#include <limits.h>

typedef struct _XDisplay Display;
typedef unsigned long XRecordContext;
typedef void* XPointer;
typedef void (*XRecordInterceptProc)(XPointer, void*);
typedef int Status;

struct XExtDisplayInfo {
    struct {
        int major_opcode;
    } *codes;
};
typedef struct XExtDisplayInfo XExtDisplayInfo;

struct xRecordEnableContextReq {
    int reqType;
    int recordReqType;
    XRecordContext context;
};
typedef struct xRecordEnableContextReq xRecordEnableContextReq;

struct xRecordEnableContextReply {
    unsigned int length;
};
typedef struct xRecordEnableContextReply xRecordEnableContextReply;

struct xReply {
    unsigned int length;
};
typedef struct xReply xReply;

struct reply_buffer {
    char *buf;
};

enum parser_return {
    Continue,
    End,
    Error
};

#define xFalse 0
#define X_RecordEnableContext 0

extern XExtDisplayInfo *find_display(Display *dpy);
extern void XRecordCheckExtension(Display *dpy, XExtDisplayInfo *info, int status);
extern void LockDisplay(Display *dpy);
extern void UnlockDisplay(Display *dpy);
extern void SyncHandle();
extern int _XReply(Display *dpy, xReply *rep, int extra, int discard);
extern void _XRead(Display *dpy, char *buf, int length);
extern struct reply_buffer *alloc_reply_buffer(XExtDisplayInfo *info, size_t size);
extern enum parser_return parse_reply_call_callback(Display *dpy, XExtDisplayInfo *info, xRecordEnableContextReply *rep, struct reply_buffer *reply, XRecordInterceptProc callback, XPointer closure);
extern void *_XGetRequest(Display *dpy, int opcode, size_t len);

#define GetReq(name, req) \
    req = (xRecordEnableContextReq *) \
          _XGetRequest(dpy, X_RecordEnableContext, sizeof(xRecordEnableContextReq))