#include <stdint.h>
#include <stddef.h>

typedef struct TIFF TIFF;
typedef struct gdImageStruct *gdImagePtr;
struct gdImageStruct {
    int sx;
    int sy;
    int alphaBlendingFlag;
};

#define GD_FAILURE 0
#define GD_SUCCESS 1
#define gdTrueColorAlpha(r, g, b, a) (((a) << 24) + ((r) << 16) + ((g) << 8) + (b))

extern void *gdCalloc(size_t nmemb, size_t size);
extern void gdFree(void *ptr);
extern void gdImageAlphaBlending(gdImagePtr im, int alphaBlendingFlag);
extern void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
extern int TIFFReadRGBAImage(TIFF* tif, uint32_t width, uint32_t height, uint32_t* raster, int stop);

#define TIFFGetR(rgba) ((rgba) & 0xff)
#define TIFFGetG(rgba) (((rgba) >> 8) & 0xff)
#define TIFFGetB(rgba) (((rgba) >> 16) & 0xff)
#define TIFFGetA(rgba) (((rgba) >> 24) & 0xff)

typedef uint32_t uint32;