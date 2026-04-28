#include <stdint.h>

typedef int32_t ClientPtr;
typedef int Bool;
typedef struct xvShmPutImageReq xvShmPutImageReq;
typedef struct PanoramiXRes PanoramiXRes;
typedef struct ScreenInfo ScreenInfo;

#define XRT_WINDOW 1
#define XRC_DRAWABLE 1
#define XRT_GC 1
#define XvXRTPort 1
#define DixWriteAccess 1
#define DixReadAccess 1
#define Success 0
#define BadValue 1
#define BadDrawable 2

struct xvShmPutImageReq {
    Bool send_event;
    int drawable;
    int gc;
    int port;
    int drw_x;
    int drw_y;
};

struct PanoramiXRes {
    int type;
    union {
        struct {
            Bool root;
        } win;
    } u;
    struct {
        int id;
    } info[1];
};

struct Screen {
    int x;
    int y;
};

struct ScreenInfo {
    struct Screen *screens[1];
};

extern xvShmPutImageReq *stuff;
extern ScreenInfo screenInfo;

static int dixLookupResourceByClass(void **ptr, int id, int class, ClientPtr client, int access) { return 0; }
static int dixLookupResourceByType(void **ptr, int id, int type, ClientPtr client, int access) { return 0; }
#define REQUEST(x)
#define REQUEST_SIZE_MATCH(x)
#define FOR_NSCREENS_BACKWARD(i) for((i) = 0; (i) >= 0; (i)--)
#define ProcXvShmPutImage(client) 0