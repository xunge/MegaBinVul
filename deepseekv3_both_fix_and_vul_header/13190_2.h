#include <stdbool.h>
#include <stddef.h>

typedef bool Bool;
typedef struct _Window *WindowPtr;
typedef struct _Screen *ScreenPtr;
typedef struct _CompScreen *CompScreenPtr;
typedef struct _CompWindow *CompWindowPtr;
typedef struct _CompSubwindows *CompSubwindowsPtr;
typedef struct _Pixmap *PixmapPtr;
typedef struct _Client *ClientPtr;

typedef enum {
    RedirectDrawNone
} RedirectDraw;

struct _Drawable {
    ScreenPtr pScreen;
};

struct _Window {
    struct _Drawable drawable;
    RedirectDraw redirectDraw;
};

struct _Screen {
    Bool (*DestroyWindow)(WindowPtr);
    PixmapPtr (*GetWindowPixmap)(WindowPtr);
    void (*DestroyPixmap)(PixmapPtr);
};

struct _CompScreen {
    Bool (*DestroyWindow)(WindowPtr);
    WindowPtr pOverlayWin;
};

struct _CompWindow {
    ClientPtr clients;
};

struct _CompSubwindows {
    ClientPtr clients;
};

struct _Client {
    unsigned long id;
};

CompScreenPtr GetCompScreen(ScreenPtr pScreen);
CompWindowPtr GetCompWindow(WindowPtr pWin);
CompSubwindowsPtr GetCompSubwindows(WindowPtr pWin);
void FreeResource(unsigned long id, int type);
void compSetParentPixmap(WindowPtr pWin);

#define RT_NONE 0