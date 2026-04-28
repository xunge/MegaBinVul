#include <limits.h>
#include <stdlib.h>

#define DEVICE_RESOLUTION 1
#define DEVICE_ABS_CALIB 2
#define DEVICE_ABS_AREA 3
#define DEVICE_CORE 4
#define DEVICE_ENABLE 5
#define XInput_Add_XChangeDeviceControl 1
#define X_GetDeviceControl 1
#define xFalse 0

typedef struct {
    int control;
    int length;
} xDeviceState;

typedef struct {
    int control;
    int length;
    int num_valuators;
} xDeviceResolutionState;

typedef struct {
    int control;
    int length;
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    int flip_x;
    int flip_y;
    int rotation;
    int button_threshold;
} xDeviceAbsCalibState;

typedef struct {
    int control;
    int length;
    int offset_x;
    int offset_y;
    int width;
    int height;
    int screen;
    int following;
} xDeviceAbsAreaState;

typedef struct {
    int control;
    int length;
    int status;
    int iscore;
} xDeviceCoreState;

typedef struct {
    int control;
    int length;
    int enable;
} xDeviceEnableState;

typedef struct {
    unsigned char reqType;
    unsigned char ReqType;
    unsigned short length;
    int deviceid;
    int control;
} xGetDeviceControlReq;

typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
    unsigned int pad6;
} xGetDeviceControlReply;

typedef struct {
    int device_id;
} XDevice;

typedef struct {
    struct {
        int major_opcode;
    } *codes;
} XExtDisplayInfo;

typedef struct {
    int control;
    int length;
} XDeviceControl;

typedef struct {
    int control;
    int length;
    int num_valuators;
    int *resolutions;
    int *min_resolutions;
    int *max_resolutions;
} XDeviceResolutionState;

typedef struct {
    int control;
    int length;
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    int flip_x;
    int flip_y;
    int rotation;
    int button_threshold;
} XDeviceAbsCalibState;

typedef struct {
    int control;
    int length;
    int offset_x;
    int offset_y;
    int width;
    int height;
    int screen;
    int following;
} XDeviceAbsAreaState;

typedef struct {
    int control;
    int length;
    int status;
    int iscore;
} XDeviceCoreState;

typedef struct {
    int control;
    int length;
    int enable;
} XDeviceEnableState;

typedef struct {
    int dummy;
} Display;

typedef struct {
    int dummy;
} xReply;

void *Xmalloc(size_t size);
void XFree(void *ptr);
void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
int _XiCheckExtInit(Display *dpy, int ext, XExtDisplayInfo *info);
XExtDisplayInfo *XInput_find_display(Display *dpy);
int _XReply(Display *dpy, xReply *rep, int extra, int discard);
void _XEatDataWords(Display *dpy, unsigned long n);
void _XRead(Display *dpy, char *data, unsigned long nbytes);
#define GetReq(name, req) ((req) = (xGetDeviceControlReq *)0)