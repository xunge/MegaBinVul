#include <stdint.h>

typedef unsigned long ClientPtr;
typedef uint32_t CARD32;

typedef struct {
    CARD32 length;
    CARD32 source;
    CARD32 destination;
    int xfixesReqType;
} xXFixesCopyRegionReq;

#define REQUEST(x) xXFixesCopyRegionReq *stuff = (xXFixesCopyRegionReq *)client
#define REQUEST_SIZE_MATCH(x)
#define REQUEST_AT_LEAST_SIZE(x)
#define swaps(x)
#define swapl(x)
#define _X_COLD

int (*ProcXFixesVector[])(ClientPtr);