#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long KeySym;

typedef struct _Display Display;
typedef struct _XDevice {
    int device_id;
} XDevice;
typedef struct _XExtDisplayInfo {
    struct {
        int major_opcode;
    } *codes;
} XExtDisplayInfo;

typedef struct _XFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
} XFeedbackState;

typedef struct _XKbdFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
    unsigned char click;
    unsigned short percent;
    unsigned short pitch;
    unsigned short duration;
    unsigned int led_mask;
    unsigned char global_auto_repeat;
    unsigned char auto_repeats[32];
} XKbdFeedbackState;

typedef struct _XPtrFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
    unsigned short accelNum;
    unsigned short accelDenom;
    unsigned short threshold;
} XPtrFeedbackState;

typedef struct _XIntegerFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
    unsigned short resolution;
    short minVal;
    short maxVal;
} XIntegerFeedbackState;

typedef struct _XStringFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
    unsigned short max_symbols;
    unsigned short num_syms_supported;
    KeySym *syms_supported;
} XStringFeedbackState;

typedef struct _XLedFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
    unsigned int led_values;
    unsigned int led_mask;
} XLedFeedbackState;

typedef struct _XBellFeedbackState {
    unsigned char class;
    unsigned short length;
    unsigned char id;
    unsigned short percent;
    unsigned short pitch;
    unsigned short duration;
} XBellFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
} xFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
    unsigned char click;
    unsigned short percent;
    unsigned short pitch;
    unsigned short duration;
    unsigned int led_mask;
    unsigned char global_auto_repeat;
    unsigned char auto_repeats[32];
} xKbdFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
    unsigned short accelNum;
    unsigned short accelDenom;
    unsigned short threshold;
} xPtrFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
    unsigned short resolution;
    short min_value;
    short max_value;
} xIntegerFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
    unsigned short max_symbols;
    unsigned short num_syms_supported;
} xStringFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
    unsigned int led_values;
    unsigned int led_mask;
} xLedFeedbackState;

typedef struct {
    unsigned char class;
    unsigned char length;
    unsigned char id;
    unsigned short percent;
    unsigned short pitch;
    unsigned short duration;
} xBellFeedbackState;

typedef struct {
    unsigned char reqType;
    unsigned char ReqType;
    unsigned short length;
    unsigned short deviceid;
} xGetFeedbackControlReq;

typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short num_feedbacks;
    unsigned short pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
    unsigned int pad6;
} xGetFeedbackControlReply;

#define KbdFeedbackClass 0
#define PtrFeedbackClass 1
#define IntegerFeedbackClass 2
#define StringFeedbackClass 3
#define LedFeedbackClass 4
#define BellFeedbackClass 5
#define X_GetFeedbackControl 1
#define xFalse 0

#define LockDisplay(dpy) 
#define UnlockDisplay(dpy) 
#define SyncHandle() 
#define GetReq(name, req) req = malloc(sizeof(xGetFeedbackControlReq))
#define _XReply(dpy, rep, n, b) 1
#define _XEatDataWords(dpy, n) 
#define _XiCheckExtInit(dpy, release, info) 0
#define XInput_find_display(dpy) ((XExtDisplayInfo*)malloc(sizeof(XExtDisplayInfo)))
#define Xmalloc(size) malloc(size)
#define XFree(ptr) free(ptr)
#define _XRead(dpy, buf, len) 