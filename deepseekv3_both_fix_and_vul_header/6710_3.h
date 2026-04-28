#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

typedef uint32_t CARD32;
typedef uint16_t CARD16;
typedef uint8_t CARD8;

typedef struct {
    CARD32 visualID;
    CARD8 depth;
    CARD8 perfLevel;
} xDbeVisInfo;

typedef struct {
    int count;
    struct {
        unsigned visual;
        unsigned depth;
        unsigned perflevel;
    } *visinfo;
} XdbeScreenVisualInfo;

typedef struct {
    CARD8 type;
    CARD16 sequenceNumber;
    CARD32 length;
    CARD32 m;
} xDbeGetVisualInfoReply;

typedef struct {
    int n;
} xDbeGetVisualInfoReq;

typedef struct {
    int numScreens;
    struct Screen **screens;
} ScreenInfo;

typedef struct Screen {
    void *pScreen;
} Screen;

typedef struct Drawable {
    Screen *pScreen;
} Drawable;

typedef Drawable *DrawablePtr;
typedef struct Client {
    void *requestBuffer;
    size_t requestLength;
    CARD16 sequence;
    int swapped;
} *ClientPtr;
typedef Screen *ScreenPtr;

typedef struct DbeScreenPriv {
    int (*GetVisualInfo)(ScreenPtr, XdbeScreenVisualInfo*);
} *DbeScreenPrivPtr;

#define REQUEST(x) x *stuff = (x *) ((ClientPtr)client)->requestBuffer
#define REQUEST_AT_LEAST_SIZE(x) \
    if (((ClientPtr)client)->requestLength < sizeof(x)) \
        return BadLength
#define REQUEST_FIXED_SIZE(x, n) \
    if (((ClientPtr)client)->requestLength != sizeof(x) + (n)) \
        return BadLength

#define BadLength 1
#define BadAlloc 2
#define Success 0
#define X_Reply 1
#define XACE_SCREEN_ACCESS 0
#define DixGetAttrAccess 0

#define DBE_SCREEN_PRIV(pScreen) ((DbeScreenPrivPtr)(pScreen))

static ScreenInfo screenInfo;

static void *xallocarray(size_t nmemb, size_t size) {
    return malloc(nmemb * size);
}

static int dixLookupDrawable(DrawablePtr *pDraw, Drawable id, ClientPtr client, int mask, int access) {
    return Success;
}

static int XaceHook(int hook, ClientPtr client, ScreenPtr pScreen, int access) {
    return Success;
}

static void swaps(uint16_t *x) {
    *x = ((*x << 8) | (*x >> 8));
}

static void swapl(uint32_t *x) {
    *x = ((*x << 24) | ((*x << 8) & 0x00FF0000) |
          ((*x >> 8) & 0x0000FF00) | (*x >> 24));
}

static int bytes_to_int32(int bytes) {
    return bytes / 4;
}

static void WriteToClient(ClientPtr client, int size, void *data) {
}