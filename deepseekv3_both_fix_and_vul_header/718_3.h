#include <stdlib.h>

#define MaxXWindows 32
#define MagickFalse 0

typedef void *Display;
typedef unsigned long Window;
typedef unsigned long Cursor;
typedef unsigned long Pixmap;
typedef void *XImage;
typedef void *GC;
typedef void *XFontStruct;
typedef void *XStandardColormap;
typedef void *XVisualInfo;
typedef void *XShmSegmentInfo;
typedef unsigned long XID;

typedef struct _XResourceInfo {
    char *name;
    void *value;
} XResourceInfo;

typedef struct _XClassHint {
    char *res_name;
    char *res_class;
} XClassHint;

typedef struct _XWMHints {
    long flags;
    int input;
    int initial_state;
    Pixmap icon_pixmap;
    Window icon_window;
    int icon_x;
    int icon_y;
    Pixmap icon_mask;
    XID window_group;
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
    XImage *matte_image;
    XImage *ximage;
    Pixmap pixmap;
    int destroy;
    void *image;
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

typedef struct _Image Image;

#define MagickExport

void DestroyXWidget(void);
XWindows *XSetWindows(XWindows *);
void *RelinquishMagickMemory(void *);
Image *DestroyImage(Image *);
Image *NewImageList(void);
char *DestroyString(char *);
void XWithdrawWindow(Display *, Window, int);
void XFreeCursor(Display *, Cursor);
void XFreePixmap(Display *, Pixmap);
void XDestroyImage(XImage *);
void XDestroyWindow(Display *, Window);
void XFreeGC(Display *, GC);
void XFreeFont(Display *, XFontStruct *);
void XFreeClassHint(XClassHint *);
void XFreeWMHints(XWMHints *);
void XFreeStandardColormap(XStandardColormap *);
void XFreeVisualInfo(XVisualInfo *);