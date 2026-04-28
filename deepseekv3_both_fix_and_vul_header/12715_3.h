#include <limits.h>
#include <string.h>

typedef int Status;
typedef unsigned short CARD16;
typedef unsigned long CARD32;

typedef struct {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    unsigned short flags;
    unsigned long pixel;
} XColor;

typedef struct {
    CARD32 exactRed;
    CARD32 exactGreen;
    CARD32 exactBlue;
} xLookupColorReply;

typedef struct {
    CARD32 cmap;
    CARD16 nbytes;
    CARD32 length;
} xLookupColorReq;

typedef struct _XDisplay Display;
typedef unsigned long Colormap;
typedef struct _XcmsCCC *XcmsCCC;
typedef struct {
    unsigned short format;
    unsigned long pixel;
} XcmsColor;

#define DoRed (1 << 0)
#define DoGreen (1 << 1)
#define DoBlue (1 << 2)

#define XcmsSuccess 0
#define XcmsSuccessWithCompression 1
#define XcmsFailure 2
#define _XCMS_NEWNAME 3
#define XcmsRGBFormat 0

#define LockDisplay(dpy)
#define UnlockDisplay(dpy)
#define SyncHandle()
#define GetReq(type, req)
#define Data(dpy, data, len)
#define _XReply(dpy, reply, extra, discard) 1
#define xTrue 1

#define _Xconst const

XcmsCCC XcmsCCCOfColormap(Display *dpy, Colormap cmap);
int _XcmsResolveColorString(XcmsCCC ccc, const char **spec, XcmsColor *color, unsigned short format);
void _XcmsRGB_to_XColor(XcmsColor *cmsColor, XColor *def, int compression);