#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long CARD32;
typedef unsigned short CARD16;
typedef unsigned char BYTE;
typedef int Bool;
#define xFalse 0

typedef struct {
    int class;
    int length;
} XInputClass;

typedef struct {
    int device_id;
    int num_classes;
    XInputClass *data;
} XDeviceState;

typedef struct {
    int class;
    int length;
    int num_keys;
    char keys[32];
} XKeyState;

typedef struct {
    int class;
    int length;
    int num_buttons;
    char buttons[32];
} XButtonState;

typedef struct {
    int class;
    int length;
    int num_valuators;
    int mode;
    int *valuators;
} XValuatorState;

typedef struct {
    int class;
    int length;
    int num_valuators;
    int mode;
} xValuatorState;

typedef struct {
    int class;
    int length;
    int num_keys;
    char keys[32];
} xKeyState;

typedef struct {
    int class;
    int length;
    int num_buttons;
    char buttons[32];
} xButtonState;

typedef struct {
    unsigned char reqType;
    unsigned char ReqType;
    CARD16 length;
    CARD16 deviceid;
} xQueryDeviceStateReq;

typedef struct {
    BYTE type;
    BYTE pad1;
    CARD16 sequenceNumber;
    CARD32 length;
    CARD16 num_classes;
    CARD16 pad2;
    CARD32 pad3;
    CARD32 pad4;
    CARD32 pad5;
    CARD32 pad6;
} xQueryDeviceStateReply;

typedef struct _XExtDisplayInfo {
    struct _XExtCodes *codes;
} XExtDisplayInfo;

typedef struct _XExtCodes {
    int major_opcode;
} XExtCodes;

typedef struct _XDevice {
    int device_id;
} XDevice;

typedef struct _XDisplay Display;

#define X_QueryDeviceState 1
#define LockDisplay(dpy) 
#define UnlockDisplay(dpy) 
#define SyncHandle() 
#define GetReq(name, req) 
#define _XReply(dpy, rep, n, b) 0
#define _XEatDataWords(dpy, n) 
#define _XRead(dpy, data, len) 
#define Xmalloc(size) malloc(size)
#define Xfree(ptr) free(ptr)
#define _XiCheckExtInit(dpy, release, info) 0
#define XInput_find_display(dpy) NULL
#define XInput_Initial_Release 0
#define KeyClass 0
#define ButtonClass 1
#define ValuatorClass 2