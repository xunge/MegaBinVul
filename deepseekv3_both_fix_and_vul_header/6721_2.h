#include <stdint.h>

#define REQUEST(x) xPanoramiXGetScreenSizeReq *stuff = (xPanoramiXGetScreenSizeReq *)client->requestBuffer
#define REQUEST_SIZE_MATCH(x) 

typedef struct _ClientRec {
    uint32_t sequence;
    unsigned char swapped;
    void *requestBuffer;
} *ClientPtr;

typedef struct _WindowRec *WindowPtr;
typedef struct _ScreenRec {
    uint32_t width;
    uint32_t height;
} *ScreenPtr;

#define BadMatch 0
#define Success 1
#define X_Reply 1
#define DixGetAttrAccess 0

extern int PanoramiXNumScreens;

typedef struct {
    ScreenPtr *screens;
} ScreenInfo;

extern ScreenInfo screenInfo;

typedef struct {
    uint8_t type;
    uint16_t sequenceNumber;
    uint32_t length;
    uint32_t width;
    uint32_t height;
    uint32_t window;
    uint32_t screen;
} xPanoramiXGetScreenSizeReply;

typedef struct {
    uint8_t reqType;
    uint8_t screen;
    uint16_t length;
    uint32_t window;
} xPanoramiXGetScreenSizeReq;

void swaps(uint16_t *);
void swapl(uint32_t *);
int dixLookupWindow(WindowPtr *, uint32_t, ClientPtr, int);
void WriteToClient(ClientPtr, int, void *);