#include <stdlib.h>
#include <limits.h>

typedef unsigned long XID;

typedef struct _Display Display;
typedef struct {
    int major_opcode;
} XExtensionCodes;

typedef struct {
    XExtensionCodes *codes;
} XExtDisplayInfo;

typedef struct {
    XID device_id;
    int num_classes;
    void *classes;
} XDevice;

typedef struct {
    unsigned char reqType;
    unsigned char ReqType;
    XID deviceid;
} xOpenDeviceReq;

typedef struct {
    unsigned long length;
    unsigned short num_classes;
} xOpenDeviceReply;

typedef struct {
    unsigned char major_opcode;
} xInputClassInfo;

typedef xInputClassInfo XInputClassInfo;

typedef struct {
    unsigned char type;
} xReply;

#define xFalse 0
#define X_OpenDevice 1
#define OpenDevice 1
#define XInput_Initial_Release 1

extern XExtDisplayInfo *XInput_find_display(Display *dpy);
extern int _XiCheckExtInit(Display *dpy, int release, XExtDisplayInfo *info);
extern void LockDisplay(Display *dpy);
extern void UnlockDisplay(Display *dpy);
extern void SyncHandle();
extern void _XRead(Display *dpy, char *data, int length);
extern void _XEatData(Display *dpy, unsigned long length);
extern void _XEatDataWords(Display *dpy, unsigned long length);
extern int _XReply(Display *dpy, xReply *reply, int extra, int discard);
extern void *Xmalloc(size_t size);
extern void GetReq(int, xOpenDeviceReq*);