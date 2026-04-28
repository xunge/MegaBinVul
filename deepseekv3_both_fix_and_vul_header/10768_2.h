#include <stdint.h>
#include <stddef.h>

#define _X_COLD
#define CARD32 uint32_t
#define ClientPtr void*
#define REQUEST(x)
#define REQUEST_AT_LEAST_SIZE(x)
#define BadLength 0
#define BadValue 0
#define NotImplemented NULL
#define swaps(x)
#define swapl(x)
#define bytes_to_int32(x) (x)
#define SwapLongs(x, y)

typedef struct {
    unsigned int type;
    union {
        struct {
            unsigned int type;
        } u;
    } u;
} xEvent;

typedef void (*EventSwapPtr)(xEvent*, xEvent*);

typedef struct {
    int length;
    int destination;
    short count;
    int num_events;
} xSendExtensionEventReq;

extern EventSwapPtr EventSwapVector[];
extern int ProcXSendExtensionEvent(ClientPtr);
extern xSendExtensionEventReq *stuff;