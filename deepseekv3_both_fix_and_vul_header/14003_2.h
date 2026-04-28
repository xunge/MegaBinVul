#include <stdlib.h>
#include <string.h>

#define MaxXWindows 32
#define MagickFalse 0

typedef void *Display;
typedef unsigned long Window;
typedef unsigned long Cursor;
typedef unsigned long Pixmap;
typedef unsigned long GC;
typedef void *XImage;
typedef void *XFontStruct;
typedef void *XStandardColormap;
typedef void *XVisualInfo;
typedef void *XResourceInfo;
typedef void *Image;

typedef struct {
    char *res_name;
    char *res_class;
} XClassHint;

typedef struct {
    int flags;
} XWMHints;

typedef struct _XWindowInfo {
    int mapped;
    Window id;
    int screen;
    char *name;
    char *icon_name;
    Cursor cursor;
    Cursor busy_cursor;
    Pixmap highlight_stipple;
    Pixmap shadow_stipple;
    XImage *ximage;
    Pixmap pixmap;
    int destroy;
    Image *image;
    Pixmap matte_pixmap;
    void *segment_info;
} XWindowInfo;

typedef struct _XPixelInfo {
    unsigned long *pixels;
    GC annotate_context;
    GC widget_context;
    GC highlight_context;
} XPixelInfo;

typedef struct _XWindows {
    Display *display;
    XWindowInfo context;
    XWindowInfo group_leader;
    XWindowInfo backdrop;
    XWindowInfo icon;
    XWindowInfo image;
    XWindowInfo info;
    XWindowInfo magnify;
    XWindowInfo pan;
    XWindowInfo command;
    XWindowInfo widget;
    XWindowInfo popup;
    XResourceInfo *icon_resources;
    XPixelInfo *icon_pixel;
    XPixelInfo *pixel_info;
    XFontStruct *font_info;
    XClassHint *class_hints;
    XWMHints *manager_hints;
    XStandardColormap *map_info;
    XStandardColormap *icon_map;
    XVisualInfo *visual_info;
    XVisualInfo *icon_visual;
} XWindows;

#define MagickExport

static inline void XWithdrawWindow(Display *d, Window w, int s) {}
static inline void XFreeCursor(Display *d, Cursor c) {}
static inline void XFreePixmap(Display *d, Pixmap p) {}
static inline void XDestroyImage(XImage *i) {}
static inline void XDestroyWindow(Display *d, Window w) {}
static inline void XFreeGC(Display *d, GC g) {}
static inline void XFreeFont(Display *d, XFontStruct *f) {}
static inline void XFree(void *p) {}

extern void DestroyXWidget(void);
extern XWindows *XSetWindows(XWindows *);
extern void *RelinquishMagickMemory(void *);
extern void *NewImageList(void);
extern void *DestroyImage(void *);
extern char *DestroyString(char *);