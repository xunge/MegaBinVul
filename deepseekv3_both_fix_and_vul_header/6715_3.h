#include <stdint.h>

typedef struct _Region *RegionPtr;

struct _Client {
    void *requestBuffer;
};
typedef struct _Client *ClientPtr;

struct xXFixesCopyRegionReq {
    uint32_t source;
    uint32_t destination;
};

#define REQUEST(x) struct x *stuff = (struct x *)client->requestBuffer
#define REQUEST_SIZE_MATCH(x)
#define VERIFY_REGION(ptr, id, client, access)
#define DixReadAccess 0
#define DixWriteAccess 0
#define BadAlloc 0
#define Success 1

int RegionCopy(RegionPtr dst, RegionPtr src);