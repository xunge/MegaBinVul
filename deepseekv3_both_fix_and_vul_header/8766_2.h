#include <stdlib.h>
#include <limits.h>

typedef struct _XFilters {
    int nfilter;
    int nalias;
    char **filter;
    short *alias;
} XFilters;

typedef unsigned long Drawable;
typedef struct _XDisplay Display;
typedef struct _XRenderExtDisplayInfo {
    struct _XRenderInfo *info;
    struct {
        int major_opcode;
    } *codes;
} XRenderExtDisplayInfo;
typedef struct _XRenderInfo {
    int minor_version;
} XRenderInfo;
typedef struct _xRenderQueryFiltersReq {
    int reqType;
    int renderReqType;
    Drawable drawable;
} xRenderQueryFiltersReq;
typedef struct _xRenderQueryFiltersReply {
    unsigned int length;
    unsigned int numFilters;
    unsigned int numAliases;
} xRenderQueryFiltersReply;
typedef struct _xReply {
    unsigned int length;
} xReply;
typedef int Bool;
#define xFalse 0
#define RenderQueryFilters 0
#define X_RenderQueryFilters 0

XRenderExtDisplayInfo *XRenderFindDisplay(Display *dpy);
Bool RenderHasExtension(XRenderExtDisplayInfo *info);
Bool XRenderQueryFormats(Display *dpy);
void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
void GetReq(int name, xRenderQueryFiltersReq *req);
Bool _XReply(Display *dpy, xReply *reply, int extra, Bool discard);
void _XRead16Pad(Display *dpy, void *data, int length);
void _XRead(Display *dpy, void *data, int length);
void _XEatData(Display *dpy, int length);
void _XEatDataWords(Display *dpy, int length);
void *Xmalloc(size_t size);