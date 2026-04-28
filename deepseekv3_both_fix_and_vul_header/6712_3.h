#include <stdint.h>
#include <stddef.h>

typedef unsigned long CARD32;
typedef struct _DeviceInt *DeviceIntPtr;
typedef struct _Client *ClientPtr;
#define PointerBarrierType 0

#define _X_UNUSED
#define REQUEST(x) xXIBarrierReleasePointerReq *stuff = (xXIBarrierReleasePointerReq *)client
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_FIXED_SIZE(x, y)
#define BadLength 0
#define BadDevice 0
#define BadAccess 0
#define Success 0
#define DixReadAccess 0

struct PointerBarrier {
    int dummy;
};

struct PointerBarrierClient {
    struct PointerBarrier barrier;
};

struct PointerBarrierDevice {
    CARD32 barrier_event_id;
    CARD32 release_event_id;
};

struct xXIBarrierReleasePointerReq {
    CARD32 num_barriers;
};
typedef struct xXIBarrierReleasePointerReq xXIBarrierReleasePointerReq;

struct xXIBarrierReleasePointerInfo {
    CARD32 barrier;
    CARD32 eventid;
    CARD32 deviceid;
};
typedef struct xXIBarrierReleasePointerInfo xXIBarrierReleasePointerInfo;

struct _Client {
    int errorValue;
    int index;
};

struct _DeviceInt {
    int id;
};

#define CLIENT_ID(x) (x)

static inline struct PointerBarrierDevice* GetBarrierDevice(struct PointerBarrierClient* barrier, int id) {
    return NULL;
}

static inline int dixLookupDevice(DeviceIntPtr* dev, CARD32 deviceid, ClientPtr client, int access) {
    return 0;
}

static inline int dixLookupResourceByType(void** res, CARD32 id, int type, ClientPtr client, int access) {
    return 0;
}

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))