#include <stdint.h>
#include <stddef.h>

typedef struct {
    int errorValue;
} ClientRec;
typedef ClientRec *ClientPtr;

typedef struct {
    struct {
        struct {
            int type;
        } u;
    } u;
} xEvent;

typedef void (*EventSwapPtr)(xEvent*, xEvent*);

typedef struct {
    int length;
    uint32_t destination;
    uint32_t eventMask;
    xEvent event;
} xSendEventReq;

#define REQUEST(x) xSendEventReq *stuff = (xSendEventReq *)(uintptr_t)client
#define REQUEST_SIZE_MATCH(x)
#define swaps(x)
#define swapl(x)
#define GenericEvent 0
#define BadValue (-1)
#define X_SendEvent 0
#define NotImplemented NULL
#define _X_COLD

extern EventSwapPtr EventSwapVector[128];
extern int (*ProcVector[256])(ClientPtr);