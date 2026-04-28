#include <limits.h>
#include <stddef.h>

typedef unsigned long Time;
typedef struct _XDisplay Display;

typedef struct {
    Time time;
    int *data;
} XDeviceTimeCoord;

typedef struct {
    int device_id;
} XDevice;

typedef struct {
    unsigned char major_opcode;
} XExtensionCodes;

typedef struct {
    XExtensionCodes *codes;
} XExtDisplayInfo;

typedef struct {
    unsigned char reqType;
    unsigned char ReqType;
    Time start;
    Time stop;
    int deviceid;
} xGetDeviceMotionEventsReq;

typedef struct {
    unsigned char mode;
    unsigned char axes;
    int nEvents;
    unsigned int length;
} xGetDeviceMotionEventsReply;

typedef struct {
    unsigned char type;
} xReply;

#define XInput_Initial_Release 0
#define xFalse 0
#define X_GetDeviceMotionEvents 0
#define GetDeviceMotionEvents 0

extern void LockDisplay(Display *dpy);
extern void UnlockDisplay(Display *dpy);
extern void SyncHandle(void);
extern void *Xmalloc(size_t size);
extern void Xfree(void *ptr);
extern void XFree(void *ptr);
extern XExtDisplayInfo *XInput_find_display(Display *dpy);
extern int _XiCheckExtInit(Display *dpy, int release, XExtDisplayInfo *info);
extern void _XRead(Display *dpy, char *data, unsigned long size);
extern void _XEatDataWords(Display *dpy, unsigned int length);
extern int _XReply(Display *dpy, xReply *rep, int extra, int discard);
extern void GetReq(int, xGetDeviceMotionEventsReq *);