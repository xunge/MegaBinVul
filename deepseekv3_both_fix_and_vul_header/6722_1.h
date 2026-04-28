typedef unsigned long XID;
typedef int ClientPtr;

#define PANORAMIX
#define XRC_DRAWABLE 0
#define Success 1
#define BadValue 2
#define BadDrawable 3
#define DixWriteAccess 0

struct xScreenSaverUnsetAttributesReq {
    XID drawable;
};

#define REQUEST(x) struct xScreenSaverUnsetAttributesReq *stuff = (void *)0
#define REQUEST_SIZE_MATCH(x) (void)0

typedef struct _PanoramiXRes {
    struct {
        XID id;
    } info[1];
} PanoramiXRes;

extern int noPanoramiXExtension;
extern int PanoramiXNumScreens;
extern int ScreenSaverUnsetAttributes(ClientPtr client);
extern int dixLookupResourceByClass(void **result, XID id, int class, ClientPtr client, int access_mode);