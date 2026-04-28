#include <limits.h>
#include <string.h>

typedef unsigned long Colormap;
typedef struct _Display Display;
typedef void* XcmsCCC;
typedef unsigned short CARD16;
typedef struct {
    unsigned short red, green, blue;
    unsigned long pixel;
    unsigned short flags;
} XColor;
typedef struct {
    unsigned short red, green, blue;
} XcmsColor;
typedef struct {
    unsigned char reqType;
    unsigned char flags;
    unsigned short length;
    unsigned long cmap;
    unsigned long pixel;
    CARD16 nbytes;
} xStoreNamedColorReq;

#define _Xconst const
#define XcmsSuccess 1
#define XcmsRGBFormat 0
#define DoRed 1
#define DoGreen 2
#define DoBlue 4

#define LockDisplay(d)
#define GetReq(a,b)
#define Data(a,b,c)
#define UnlockDisplay(d)
#define SyncHandle()
#define _XcmsRGB_to_XColor(a,b,c)
#define _XcmsResolveColorString(a,b,c,d) 0
#define XcmsCCCOfColormap(a,b) NULL
#define XStoreColor(a,b,c) 0