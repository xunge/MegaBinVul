#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct {
    int shmid;
    char *shmaddr;
    int readOnly;
} XShmSegmentInfo;

typedef struct {
    int width;
    int height;
    int bytes_per_line;
    char *data;
    int depth;
    int format;
} XImage;

typedef struct _XDisplay Display;
typedef struct _XVisual Visual;

#define ZPixmap 2
#define False 0

extern Display *dpy;
extern int nofb;
extern int using_shm;
extern int xform24to32;
extern int raw_fb;
extern Visual *default_visual;
extern int depth;
extern int flip_byte_order;
extern int quiet;
extern int BitmapPad(Display *dpy);
extern XImage *XCreateImage_wr(Display *display, Visual *visual, unsigned int depth, int format, int offset, char *data, unsigned int width, unsigned int height, int bitmap_pad, int bytes_per_line);
extern XImage *XShmCreateImage_wr(Display *display, Visual *visual, unsigned int depth, int format, char *data, XShmSegmentInfo *shminfo, unsigned int width, unsigned int height);
extern int XShmAttach_wr(Display *display, XShmSegmentInfo *shminfo);
extern void XDestroyImage(XImage *image);
extern void X_LOCK;
extern void X_UNLOCK;
extern void rfbErr(const char *format, ...);
extern void rfbLog(const char *format, ...);
extern void rfbLogPerror(const char *s);
extern char *flip_ximage_byte_order(XImage *xim);