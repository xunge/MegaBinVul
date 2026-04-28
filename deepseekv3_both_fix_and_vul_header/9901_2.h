#include <stdio.h>
#include <string.h>

typedef struct Display Display;

typedef struct {
    int width;
    int height;
    int mwidth;
    int mheight;
} Screen;

typedef struct {
    int bits_per_rgb;
    int class;
    int visualid;
} Visual;

typedef struct {
    int screen;
    int class;
    int depth;
    int visualid;
} XVisualInfo;

typedef char* String;

enum {
    StaticGray,
    GrayScale,
    StaticColor,
    PseudoColor,
    TrueColor,
    DirectColor,
    VisualScreenMask
};

static const char *ClassNames[] = {
    "StaticGray",
    "GrayScale",
    "StaticColor",
    "PseudoColor",
    "TrueColor",
    "DirectColor"
};

static Screen* ScreenOfDisplay(Display *display, int scrno);
static Visual* DefaultVisualOfScreen(Screen *screen);
static XVisualInfo* XGetVisualInfo(Display *display, int mask, XVisualInfo *vinfo, int *nitems);
static void XFree(void *data);
static int DisplayPlanes(Display *display, int scrno);
static void AddNum(String *defs, const char *name, int value);
static void AddDef(String *defs, const char *name, const char *value);
static void AddSimpleDef(String *defs, const char *name);
static int Resolution(int a, int b);