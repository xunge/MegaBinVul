#include <stdint.h>

#define _X_COLD

typedef uint32_t CARD32;
typedef uint16_t CARD16;
typedef uint8_t CARD8;
typedef unsigned long Window;
typedef unsigned long ClientPtr;

typedef struct {
    CARD8 reqType;
    CARD8 xfixesReqType;
    CARD16 length;
    Window window;
} xXFixesChangeSaveSetReq;

extern int (*ProcXFixesVector[])(ClientPtr);

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_SIZE_MATCH(x)
#define swaps(x)
#define swapl(x)