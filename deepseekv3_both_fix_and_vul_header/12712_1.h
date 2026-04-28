#include <limits.h>
#include <string.h>

typedef unsigned long Window;
typedef struct _XDisplay Display;
#define _Xconst const
#define USHRT_MAX 65535
#define XA_WM_ICON_NAME 0
#define XA_STRING 0
#define PropModeReplace 0

int XChangeProperty(Display *dpy, Window w, int property, int type, int format, int mode, const unsigned char *data, int nelements);