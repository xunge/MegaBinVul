#include <stdint.h>
#include <limits.h>

typedef struct {
    uint32_t resultBytes;
    uint32_t numSizes;
    void *specs;
    void *response;
} ConstructResourceBytesCtx;

typedef struct {
    uint32_t numSpecs;
    uint32_t client;
} xXResQueryResourceBytesReq;

typedef struct {
    uint8_t type;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t numSizes;
} xXResQueryResourceBytesReply;

typedef struct {
    uint16_t sequence;
    uint8_t swapped;
} ClientRec;
typedef ClientRec *ClientPtr;

#define X_Reply 1
#define BadLength 1
#define BadAlloc 1
#define Success 1
#define sz_xXResQueryResourceBytesReq sizeof(xXResQueryResourceBytesReq)

#define REQUEST(x) xXResQueryResourceBytesReq *stuff = (xXResQueryResourceBytesReq *)((char *)client + sizeof(ClientRec))
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_FIXED_SIZE(x, y)

static inline uint32_t bytes_to_int32(uint32_t x) { return x; }

extern int InitConstructResourceBytesCtx(ConstructResourceBytesCtx *ctx, ClientPtr client, uint32_t numSpecs, void *data);
extern int ConstructResourceBytes(uint32_t client, ConstructResourceBytesCtx *ctx);
extern void DestroyConstructResourceBytesCtx(ConstructResourceBytesCtx *ctx);
extern void swaps(uint16_t *);
extern void swapl(uint32_t *);
extern void SwapXResQueryResourceBytes(void *);
extern void WriteToClient(ClientPtr client, int size, void *data);
extern void WriteFragmentsToClient(ClientPtr client, void *response);