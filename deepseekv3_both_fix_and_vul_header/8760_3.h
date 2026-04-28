#include <limits.h>
#include <string.h>

typedef struct {
    int deviceid;
    int use;
    int attachment;
    int enabled;
    char *name;
    void *classes;
    int num_classes;
} XIDeviceInfo;

typedef struct {
    struct {
        int major_opcode;
    } *codes;
} XExtDisplayInfo;

typedef struct {
    int reqType;
    int ReqType;
    int deviceid;
} xXIQueryDeviceReq;

typedef struct {
    int length;
    int num_devices;
} xXIQueryDeviceReply;

typedef struct {
    int deviceid;
    int use;
    int attachment;
    int enabled;
    int num_classes;
    int name_len;
} xXIDeviceInfo;

typedef struct {
    int type;
} xXIAnyInfo;

typedef struct {
    int type;
} xReply;

typedef struct {
    int dummy;
} Display;

#define XInput_2_0 0
#define xFalse 0
#define X_XIQueryDevice 1
#define XIQUERYDEVICE_OPCODE 1

extern XExtDisplayInfo *XInput_find_display(Display *dpy);
extern int _XiCheckExtInit(Display *dpy, int major, XExtDisplayInfo *extinfo);
extern size_t size_classes(xXIAnyInfo *ptr, int nclasses);
extern int copy_classes(XIDeviceInfo *lib, xXIAnyInfo *ptr, int *nclasses);
extern void LockDisplay(Display *dpy);
extern void UnlockDisplay(Display *dpy);
extern void SyncHandle(void);
extern void GetReq(int, xXIQueryDeviceReq *);
extern int _XReply(Display *dpy, xReply *reply, int extra, int discard);
extern void _XRead(Display *dpy, char *buf, int length);
extern void *Xmalloc(size_t size);
extern void *Xcalloc(size_t nmemb, size_t size);
extern void Xfree(void *ptr);