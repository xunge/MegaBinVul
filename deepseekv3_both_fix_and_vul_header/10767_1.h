#include <stdint.h>
#include <stddef.h>

typedef struct ClientRec *ClientPtr;
typedef struct _DeviceIntRec *DeviceIntPtr;
typedef struct _XEvent xEvent;
typedef struct _XEventClass XEventClass;
typedef struct {
    unsigned int length;
    unsigned int deviceid;
    unsigned int count;
    unsigned int num_events;
    unsigned int destination;
    unsigned int propagate;
} xSendExtensionEventReq;

#define EMASKSIZE 1
#define EXTENSION_EVENT_BASE 0
#define lastEvent 0
#define X_SendExtensionEvent 0
#define BadLength 0
#define BadValue 0
#define Success 0
#define DixWriteAccess 0

struct tmask {
    int mask;
};

struct ClientRec {
    int errorValue;
};

struct _DeviceIntRec;
struct _XEvent {
    struct {
        struct {
            int type;
        } u;
    } u;
};

static xSendExtensionEventReq *stuff;

int bytes_to_int32(size_t size);
int dixLookupDevice(DeviceIntPtr *dev, int deviceid, ClientPtr client, int access);
int CreateMaskFromList(ClientPtr client, XEventClass *list, int count, struct tmask *tmp, DeviceIntPtr dev, int type);
int SendEvent(ClientPtr client, DeviceIntPtr dev, int destination, int propagate, xEvent *event, int mask, int num_events);

#define REQUEST(type) 
#define REQUEST_AT_LEAST_SIZE(type)