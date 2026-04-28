#include <limits.h>
#include <stddef.h>

typedef int Status;
typedef unsigned long CARD32;
typedef void* XPointer;

#define RENDER_MAJOR 0
#define RENDER_MINOR 0
#define SubPixelUnknown 0
#define xFalse 0
#define X_RenderQueryVersion 0
#define X_RenderQueryPictFormats 1
#define RenderQueryVersion 0
#define RenderQueryPictFormats 1
#define INT_MAX __INT_MAX__
#define False 0

typedef struct _XDisplay {
    unsigned long request;
    struct _XAsyncHandler* async_handlers;
    /* Other members omitted for brevity */
} Display;

typedef struct _XRenderExtDisplayInfo {
    void* info;
    struct {
        int major_opcode;
    } *codes;
} XRenderExtDisplayInfo;

typedef struct _XAsyncHandler {
    struct _XAsyncHandler* next;
    int (*handler)(void);
    XPointer data;
} _XAsyncHandler;

typedef struct _XrenderVersionState {
    unsigned long version_seq;
    int error;
    int major_version;
    int minor_version;
} _XrenderVersionState;

typedef struct xRenderQueryVersionReq {
    int reqType;
    int renderReqType;
    int majorVersion;
    int minorVersion;
} xRenderQueryVersionReq;

typedef struct xRenderQueryPictFormatsReply {
    int numFormats;
    int numScreens;
    int numDepths;
    int numVisuals;
    int numSubpixel;
    unsigned long length;
} xRenderQueryPictFormatsReply;

typedef struct xRenderQueryPictFormatsReq {
    int reqType;
    int renderReqType;
} xRenderQueryPictFormatsReq;

typedef struct _XRenderInfo {
    int major_version;
    int minor_version;
    struct _XRenderPictFormat* format;
    int nformat;
    struct _XRenderScreen* screen;
    int nscreen;
    struct _XRenderDepth* depth;
    int ndepth;
    struct _XRenderVisual* visual;
    int nvisual;
} XRenderInfo;

typedef struct _XRenderPictFormat {
    int id;
    int type;
    int depth;
    struct {
        int red;
        int redMask;
        int green;
        int greenMask;
        int blue;
        int blueMask;
        int alpha;
        int alphaMask;
    } direct;
    int colormap;
} XRenderPictFormat;

typedef struct _XRenderScreen {
    struct _XRenderDepth* depths;
    int ndepths;
    struct _XRenderPictFormat* fallback;
    int subpixel;
} XRenderScreen;

typedef struct _XRenderDepth {
    int depth;
    int nvisuals;
    struct _XRenderVisual* visuals;
} XRenderDepth;

typedef struct _XRenderVisual {
    void* visual;
    struct _XRenderPictFormat* format;
} XRenderVisual;

typedef struct xPictFormInfo {
    int id;
    int type;
    int depth;
    struct {
        int red;
        int redMask;
        int green;
        int greenMask;
        int blue;
        int blueMask;
        int alpha;
        int alphaMask;
    } direct;
    int colormap;
} xPictFormInfo;

typedef struct xPictScreen {
    int nDepth;
    int fallback;
} xPictScreen;

typedef struct xPictDepth {
    int depth;
    int nPictVisuals;
} xPictDepth;

typedef struct xPictVisual {
    int visual;
    int format;
} xPictVisual;

typedef struct _XReply xReply;

void* Xmalloc(size_t size);
void Xfree(void* ptr);
void _XRead(Display* dpy, char* data, unsigned long length);
void _XEatDataWords(Display* dpy, unsigned long length);
void _XEatData(Display* dpy, unsigned long length);
void LockDisplay(Display* dpy);
void UnlockDisplay(Display* dpy);
void SyncHandle(void);
void RenderCheckExtension(Display* dpy, void* info, int i);
void GetReq(int a, void* b);
void DeqAsyncHandler(Display* dpy, void* async);
int _XReply(Display* dpy, xReply* rep, int i, int j);
XRenderExtDisplayInfo* XRenderFindDisplay(Display* dpy);
XRenderPictFormat* _XRenderFindFormat(XRenderInfo* xri, int format);
void* _XRenderFindVisual(Display* dpy, int visual);
int _XRenderVersionHandler(void);