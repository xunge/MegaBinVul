#include <stdint.h>
#include <string.h>

typedef struct _rfbClient rfbClient;
typedef struct _rfbClient* rfbClientPtr;
typedef struct _rfbScreenInfo* rfbScreenInfoPtr;
typedef struct _rfbClientIterator* rfbClientIteratorPtr;

typedef struct {
    uint8_t type;
    uint8_t pad[3];
    uint32_t length;
} rfbServerCutTextMsg;

#define rfbServerCutText 3
#define sz_rfbServerCutTextMsg 8

#define Swap32IfLE(x) (x)
#define LOCK(x)
#define UNLOCK(x)