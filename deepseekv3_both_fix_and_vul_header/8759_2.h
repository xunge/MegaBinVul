#include <stdlib.h>
#include <limits.h>

typedef struct _Display Display;
typedef struct _XExtDisplayInfo {
    struct {
        unsigned char major_opcode;
    } *codes;
} XExtDisplayInfo;
typedef struct _XDevice {
    int device_id;
} XDevice;
typedef struct _XModifierKeymap {
    int max_keypermod;
    unsigned char *modifiermap;
} XModifierKeymap;
typedef unsigned char KeyCode;

typedef struct {
    unsigned char reqType;
    unsigned char ReqType;
    unsigned short length;
    unsigned int deviceid;
} xGetDeviceModifierMappingReq;

typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned int length;
    unsigned short numKeyPerModifier;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
    unsigned int pad5;
    unsigned int pad6;
} xGetDeviceModifierMappingReply;

typedef struct {
    unsigned char type;
    unsigned char pad1;
    unsigned short sequenceNumber;
    unsigned int length;
} xReply;

#define xFalse 0
#define XInput_Initial_Release 0
#define GetDeviceModifierMapping 0
#define X_GetDeviceModifierMapping 0

XExtDisplayInfo *XInput_find_display(Display *dpy);
int _XiCheckExtInit(Display *dpy, int release, XExtDisplayInfo *info);
void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);
void SyncHandle(void);
void _XReadPad(Display *dpy, char *data, unsigned long nbytes);
void _XEatDataWords(Display *dpy, unsigned long n);
void *Xmalloc(size_t size);
void GetReq(int, xGetDeviceModifierMappingReq *);
int _XReply(Display *, xReply *, int, int);