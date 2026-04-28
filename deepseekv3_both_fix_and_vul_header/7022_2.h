#include <stddef.h>

typedef unsigned long Cursor;
typedef unsigned long Pixmap;
typedef unsigned long GC;

struct XGCValues;
typedef struct XGCValues XGCValues;

typedef struct {
    unsigned long norm_pixel;
} XColor;

typedef struct {
    void *dpy;
    unsigned long wid;
    XColor norm_pixel;
} Gui;

static Gui gui;