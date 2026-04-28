typedef struct {
    int w;
    int h;
} PseudoramiXScreen;

typedef struct {
    unsigned char type;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned int width;
    unsigned int height;
    unsigned int window;
    unsigned int screen;
} xPanoramiXGetScreenSizeReply;

typedef struct {
    int screen;
    unsigned int window;
} xPanoramiXGetScreenSizeReq;

extern int pseudoramiXNumScreens;
extern PseudoramiXScreen pseudoramiXScreens[];

typedef struct _ClientRec {
    void *requestBuffer;
    unsigned short sequence;
    int swapped;
} *ClientPtr;

typedef struct _WindowRec *WindowPtr;

#define BadMatch 8
#define Success 1
#define TRACE
#define REQUEST(x) x *stuff = (x*) client->requestBuffer
#define REQUEST_SIZE_MATCH(x)
#define DixGetAttrAccess 0
#define dixLookupWindow(a,b,c,d) 0
#define WriteToClient(a,b,c)
#define swaps(x)
#define swapl(x)
#define X_Reply 1