#include <stdlib.h>
#include <string.h>

typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct;

typedef struct {
    int width;
    int height;
    int ncolors;
    struct {
        char *c_color;
    } *colorTable;
    char *data;
} XpmImage;

typedef struct {
    int dummy;
} XpmInfo;

#define XpmSuccess 0

extern void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
extern gdImagePtr gdImageCreate(int sx, int sy);
extern int gdImageColorResolve(gdImagePtr im, int r, int g, int b);
extern void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
extern void gdFree(void *ptr);
extern int XpmReadFileToXpmImage(char *filename, XpmImage *image, XpmInfo *info);
extern void XpmFreeXpmImage(XpmImage *image);
extern void XpmFreeXpmInfo(XpmInfo *info);