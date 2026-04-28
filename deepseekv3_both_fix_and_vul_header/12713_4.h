#include <limits.h>
#include <string.h>

typedef struct _XDisplay Display;
typedef unsigned long Window;
#define _Xconst const

#define XA_WM_NAME 0
#define XA_STRING 1
#define PropModeReplace 0

int XChangeProperty(Display *dpy, Window w, int property, int type, int format, int mode, const unsigned char *data, int nelements);