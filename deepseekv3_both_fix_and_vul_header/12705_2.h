#include <stddef.h>
#include <limits.h>

#define _Xconst const
#define None 0L
#define PropModeReplace 0
#define IconPixmapHint (1L << 1)
#define XA_WM_ICON_NAME 0
#define XA_STRING 0

typedef unsigned long Window;
typedef unsigned long Pixmap;
typedef struct _XDisplay Display;
typedef struct {
    long flags;
    Pixmap icon_pixmap;
} XWMHints;
typedef struct {
    long flags;
} XSizeHints;

size_t safestrlen(const char *s);