#include <stdint.h>

typedef uint32_t CARD32;
typedef uint16_t CARD16;
typedef uint8_t CARD8;
typedef intptr_t ClientPtr;

typedef struct {
    CARD8 reqType;
    CARD8 xfixesReqType;
    CARD16 length;
    CARD32 majorVersion;
    CARD32 minorVersion;
} xXFixesQueryVersionReq;

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_SIZE_MATCH(x)
#define swaps(x)
#define swapl(x)
#define _X_COLD

static int (*ProcXFixesVector[256])(ClientPtr);