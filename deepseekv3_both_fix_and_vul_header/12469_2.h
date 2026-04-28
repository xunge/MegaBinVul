#include <stdint.h>
#include <string.h>

#define DixManageAccess 0

typedef struct _ClientRec {
    int swapped;
} *ClientPtr;

typedef struct _DeviceIntRec *DeviceIntPtr;
typedef struct _KbdFeedbackRec *KbdFeedbackPtr;
typedef struct _PtrFeedbackRec *PtrFeedbackPtr;
typedef struct _IntegerFeedbackRec *IntegerFeedbackPtr;
typedef struct _StringFeedbackRec *StringFeedbackPtr;
typedef struct _BellFeedbackRec *BellFeedbackPtr;
typedef struct _LedFeedbackRec *LedFeedbackPtr;

typedef struct {
    int id;
} FeedbackCtrl;

struct _KbdFeedbackRec {
    FeedbackCtrl ctrl;
    struct _KbdFeedbackRec *next;
};

struct _PtrFeedbackRec {
    FeedbackCtrl ctrl;
    struct _PtrFeedbackRec *next;
};

struct _IntegerFeedbackRec {
    FeedbackCtrl ctrl;
    struct _IntegerFeedbackRec *next;
};

struct _StringFeedbackRec {
    FeedbackCtrl ctrl;
    struct _StringFeedbackRec *next;
};

struct _BellFeedbackRec {
    FeedbackCtrl ctrl;
    struct _BellFeedbackRec *next;
};

struct _LedFeedbackRec {
    FeedbackCtrl ctrl;
    struct _LedFeedbackRec *next;
};

struct _DeviceIntRec {
    KbdFeedbackPtr kbdfeed;
    PtrFeedbackPtr ptrfeed;
    IntegerFeedbackPtr intfeed;
    StringFeedbackPtr stringfeed;
    BellFeedbackPtr bell;
    LedFeedbackPtr leds;
};

typedef struct {
    int deviceid;
    int feedbackid;
    int mask;
    int length;
} xChangeFeedbackControlReq;

typedef struct {
    int id;
} xKbdFeedbackCtl;

typedef struct {
    int id;
} xPtrFeedbackCtl;

typedef struct {
    int id;
    int num_keysyms;
} xStringFeedbackCtl;

typedef struct {
    int id;
} xIntegerFeedbackCtl;

typedef struct {
    int id;
} xLedFeedbackCtl;

typedef struct {
    int id;
} xBellFeedbackCtl;

#define KbdFeedbackClass 0
#define PtrFeedbackClass 1
#define StringFeedbackClass 2
#define IntegerFeedbackClass 3
#define LedFeedbackClass 4
#define BellFeedbackClass 5

#define BadLength 0
#define BadMatch 0
#define Success 1

#define REQUEST(x) x *stuff = (x *)client
#define REQUEST_AT_LEAST_SIZE(x)
#define REQUEST_AT_LEAST_EXTRA_SIZE(x, y)

static inline int bytes_to_int32(int bytes) { return bytes / 4; }

static inline void swaps(int *x) { 
    *x = ((*x << 8) & 0xff00) | ((*x >> 8) & 0x00ff); 
}

int dixLookupDevice(DeviceIntPtr *dev, int deviceid, ClientPtr client, int access);
int ChangeKbdFeedback(ClientPtr client, DeviceIntPtr dev, int mask, KbdFeedbackPtr k, xKbdFeedbackCtl *ctl);
int ChangePtrFeedback(ClientPtr client, DeviceIntPtr dev, int mask, PtrFeedbackPtr p, xPtrFeedbackCtl *ctl);
int ChangeStringFeedback(ClientPtr client, DeviceIntPtr dev, int mask, StringFeedbackPtr s, xStringFeedbackCtl *ctl);
int ChangeIntegerFeedback(ClientPtr client, DeviceIntPtr dev, int mask, IntegerFeedbackPtr i, xIntegerFeedbackCtl *ctl);
int ChangeLedFeedback(ClientPtr client, DeviceIntPtr dev, int mask, LedFeedbackPtr l, xLedFeedbackCtl *ctl);
int ChangeBellFeedback(ClientPtr client, DeviceIntPtr dev, int mask, BellFeedbackPtr b, xBellFeedbackCtl *ctl);