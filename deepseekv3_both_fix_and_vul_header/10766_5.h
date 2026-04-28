#include <stdint.h>
#include <stddef.h>

typedef struct _Client {
    int errorValue;
} ClientRec, *ClientPtr;

typedef struct _Window {
    struct _Window *parent;
    uint32_t dontPropagateMask;
} *WindowPtr;

typedef struct _SpriteInfo {
    struct _SpriteRec *sprite;
} *SpriteInfoPtr;

typedef struct _SpriteRec {
    WindowPtr win;
} *SpritePtr;

typedef struct _Focus {
    WindowPtr win;
} *FocusPtr;

typedef struct _DeviceIntRec {
    SpriteInfoPtr spriteInfo;
    FocusPtr focus;
} *DeviceIntPtr;

typedef struct _GrabRec *GrabPtr;

typedef struct {
    struct {
        struct {
            uint32_t type;
            uint32_t detail;
        } u;
    } u;
} xEvent;

typedef struct {
    xEvent event;
    uint32_t eventMask;
    uint32_t propagate;
    uint32_t destination;
} xSendEventReq;

#define NullWindow ((WindowPtr)0)
#define NoneWin ((WindowPtr)0)
#define PointerRootWin ((WindowPtr)0)
#define NullGrab ((GrabPtr)0)

#define MASTER_KEYBOARD 0
#define SEND_EVENT_BIT 0x80
#define EXTENSION_EVENT_BASE 128
#define AllEventMasks 0xFFFFFFFF
#define xFalse 0
#define xTrue 1
#define X_Reply 1
#define LASTEvent 35
#define lastEvent 35
#define GenericEvent 35
#define ClientMessage 33
#define PointerWindow 0
#define InputFocus 1
#define BadValue 2
#define BadWindow 3
#define Success 0
#define DixSendAccess 0
#define XACE_SEND_ACCESS 0

extern DeviceIntPtr PickPointer(ClientPtr client);
extern DeviceIntPtr GetMaster(DeviceIntPtr dev, int type);
extern WindowPtr GetCurrentRootWindow(DeviceIntPtr dev);
extern int IsParent(WindowPtr p1, WindowPtr p2);
extern int XaceHook(int, ClientPtr, void*, WindowPtr, void*, int);
extern int DeliverEventsToWindow(DeviceIntPtr dev, WindowPtr pWin, void* event, int count, unsigned int mask, GrabPtr grab);
extern int dixLookupWindow(WindowPtr* pWin, unsigned int id, ClientPtr client, int access_mode);
extern unsigned int wDontPropagateMask(WindowPtr pWin);

#define REQUEST(x) xSendEventReq *stuff = (xSendEventReq *)client
#define REQUEST_SIZE_MATCH(x) (void)0