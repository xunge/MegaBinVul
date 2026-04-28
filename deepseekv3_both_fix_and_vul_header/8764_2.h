#include <string.h>

typedef struct _Display Display;
typedef struct _XDevice {
    int device_id;
} XDevice;

typedef struct _XExtDisplayInfo {
    struct {
        int major_opcode;
    } *codes;
} XExtDisplayInfo;

typedef struct _xGetDeviceButtonMappingReq {
    unsigned char reqType;
    unsigned char ReqType;
    int deviceid;
} xGetDeviceButtonMappingReq;

typedef struct _xGetDeviceButtonMappingReply {
    unsigned int length;
    unsigned int nElts;
} xGetDeviceButtonMappingReply;

typedef struct _xReply {
    // minimal xReply structure
} xReply;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define xFalse 0
#define NoSuchExtension -1
#define XInput_Initial_Release 0
#define X_GetDeviceButtonMapping 123 // dummy value
#define GetDeviceButtonMapping 123 // dummy value

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
int _XiCheckExtInit(Display *dpy, int release, XExtDisplayInfo *info);
XExtDisplayInfo *XInput_find_display(Display *dpy);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
void _XRead(Display *dpy, char *data, unsigned long nbytes);
void _XEatDataWords(Display *dpy, unsigned long length);
void GetReq(int, xGetDeviceButtonMappingReq*);