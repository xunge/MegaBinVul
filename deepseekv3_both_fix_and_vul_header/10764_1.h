#include <stdint.h>
#include <stddef.h>

typedef struct _Client {
    int errorValue;
} *ClientPtr;

typedef uint32_t CARD32;

typedef struct {
    int length;
    CARD32 destination;
    short count;
    int num_events;
} xSendExtensionEventReq;

typedef struct {
    union {
        struct {
            int type;
        } u;
    } u;
} xEvent;

typedef void (*EventSwapPtr)(xEvent*, xEvent*);

#define NotImplemented NULL
#define BadLength 1
#define BadValue 2
#define GenericEvent 0

extern xSendExtensionEventReq *stuff;
extern EventSwapPtr EventSwapVector[];

#define REQUEST(x) 
#define REQUEST_AT_LEAST_SIZE(x) 
#define swaps(x) 
#define swapl(x) 
#define bytes_to_int32(x) ((x)/4)
#define _X_COLD 
#define SwapLongs(p, count) 
#define ProcXSendExtensionEvent(client) 0