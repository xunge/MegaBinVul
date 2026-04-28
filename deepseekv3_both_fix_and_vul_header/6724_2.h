#include <stdint.h>
#include <string.h>

typedef uint32_t CARD32;

struct _ClientRec {
    void *requestBuffer;
};

typedef struct _ClientRec *ClientPtr;

typedef struct {
    CARD32 numSpecs;
} xXResQueryResourceBytesReq;

typedef struct {
    CARD32 resource;
    CARD32 type;
} xXResResourceIdSpec;

#define _X_COLD __attribute__((cold))
#define REQUEST(x) x *stuff = (x*) client->requestBuffer
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_FIXED_SIZE(x, y)

static inline void swapl(CARD32 *x) {
    CARD32 val = *x;
    *x = ((val >> 24) & 0xff) | ((val >> 8) & 0xff00) |
          ((val << 8) & 0xff0000) | ((val << 24) & 0xff000000);
}

static inline void SwapXResResourceIdSpec(xXResResourceIdSpec *spec) {
    swapl(&spec->resource);
    swapl(&spec->type);
}

static inline int ProcXResQueryResourceBytes(ClientPtr client) {
    return 0;
}