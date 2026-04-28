#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>

typedef unsigned int GLuint;
typedef int GLboolean;
#define GL_FALSE 0
#define GL_TRUE 1

typedef void* GC;
typedef struct {
    int type;
} XErrorEvent;

#define ZPixmap 2
#define False 0

typedef struct XMesaBuffer *XMesaBuffer;
typedef struct XMesaDisplay *XMesaDisplay;
typedef struct XMesaVisual *XMesaVisual;
typedef struct XMesaXRB *XMesaXRB;

struct XMesaVisual {
    void *display;
    struct {
        void *visual;
        int depth;
    } *visinfo;
};

struct XMesaXRB {
    struct {
        char *data;
        int bytes_per_line;
        int height;
    } *ximage;
    unsigned long drawable;
};

struct XMesaBuffer {
    struct XMesaVisual *xm_visual;
    struct XMesaXRB *backxrb;
    struct XMesaXRB *frontxrb;
    struct {
        int shmid;
        char *shmaddr;
        int readOnly;
    } shminfo;
    int shm;
};

static int mesaXErrorFlag = 0;
static int mesaHandleXError(XMesaDisplay *dpy, XErrorEvent *event) { return 0; }
static void _mesa_warning(void*, const char*) {}
static void* XShmCreateImage(void*, void*, int, int, void*, void*, int, int) { return NULL; }
static void XDestroyImage(void*) {}
static void* XSetErrorHandler(void*) { return NULL; }
static void XShmAttach(void*, void*) {}
static void XSync(void*, int) {}
static void XFlush(void*) {}
static void* XCreateGC(void*, unsigned long, int, void*) { return NULL; }
static void XShmPutImage(void*, unsigned long, void*, void*, int, int, int, int, int, int, int) {}
static void XFreeGC(void*, void*) {}