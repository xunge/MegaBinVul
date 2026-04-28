#include <limits.h>
#include <string.h>

typedef int Status;
typedef unsigned long Colormap;
typedef unsigned short CARD16;
typedef unsigned char BOOL;
#define xTrue 1

typedef struct {
    unsigned short red, green, blue;
    unsigned long pixel;
} XColor;

typedef struct {
    CARD16 exactRed, exactGreen, exactBlue;
    CARD16 screenRed, screenGreen, screenBlue;
    unsigned long pixel;
} xAllocNamedColorReply;

typedef struct {
    unsigned char reqType;
    unsigned char pad;
    CARD16 length;
    Colormap cmap;
    CARD16 nbytes;
    CARD16 pad1;
} xAllocNamedColorReq;

typedef void* XcmsCCC;
typedef struct {
    unsigned short format;
    struct {
        double red, green, blue;
    } spec;
} XcmsColor;

#define XcmsSuccess 0
#define XcmsSuccessWithCompression 1
#define XcmsFailure 2
#define _XCMS_NEWNAME 3

typedef struct _XDisplay Display;
#define _Xconst const

#define AllocNamedColor 1

typedef struct {
    unsigned char type;
    unsigned char pad1;
    CARD16 sequenceNumber;
    unsigned int length;
    unsigned char pad2[24];
} xReply;

void LockDisplay(Display*);
void UnlockDisplay(Display*);
void GetReq(int, xAllocNamedColorReq*);
void _XSend(Display*, const char*, long);
BOOL _XReply(Display*, xReply*, int, BOOL);
void SyncHandle(void);