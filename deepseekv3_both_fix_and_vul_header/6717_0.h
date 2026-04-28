#include <stdint.h>

typedef unsigned char ClientPtr;
typedef uint32_t CARD32;
typedef uint16_t CARD16;

typedef struct {
    int length;
    int num_devices;
    CARD32 barrier;
    CARD32 window;
    CARD16 x1;
    CARD16 y1;
    CARD16 x2;
    CARD16 y2;
    CARD32 directions;
    int xfixesReqType;
} xXFixesCreatePointerBarrierReq;

extern int (*ProcXFixesVector[])(ClientPtr);

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_FIXED_SIZE(x, y)
#define pad_to_int32(x) ((x + 3) & ~3)

static inline void swaps(CARD16 *x) { *x = (*x << 8) | (*x >> 8); }
static inline void swapl(CARD32 *x) { *x = (*x << 24) | ((*x << 8) & 0x00FF0000) | ((*x >> 8) & 0x0000FF00) | (*x >> 24); }

#define _X_COLD