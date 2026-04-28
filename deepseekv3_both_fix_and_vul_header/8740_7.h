#include <stdint.h>
#include <limits.h>

struct _DrawableRec;
struct _GCRec;

typedef struct _ClientRec {
    char *requestBuffer;
    unsigned int errorValue;
    unsigned int req_len;
} *ClientPtr;

typedef struct _GCRec {
    struct _GCOps {
        void (*PutImage)(struct _DrawableRec*, struct _GCRec*, unsigned int,
                        unsigned int, unsigned int, unsigned int, unsigned int,
                        unsigned int, unsigned int, char*);
    } *ops;
} GC;

typedef struct _DrawableRec {
    unsigned int depth;
} *DrawablePtr;

struct _ScreenInfo {
    unsigned int bitmapScanlinePad;
} screenInfo;

typedef struct {
    unsigned int drawable;
    unsigned int format;
    unsigned int depth;
    unsigned int width;
    unsigned int height;
    unsigned int dstX;
    unsigned int dstY;
    unsigned int leftPad;
} xPutImageReq;

#define XYBitmap 0
#define XYPixmap 1
#define ZPixmap 2

#define REQUEST(x) x *stuff = (x *)client->requestBuffer
#define REQUEST_AT_LEAST_SIZE(x)
#define VALIDATE_DRAWABLE_AND_GC(drawable, pDraw, access)
#define DixWriteAccess 0
#define BadMatch 1
#define BadValue 2
#define BadLength 3
#define Success 0

#define BitmapBytePad(x) (((x) + 7) >> 3)
#define PixmapBytePad(w, d) (((((w) * (d) + 7) >> 3) + 3) & ~3)
#define BitsPerPixel(d) ((d) <= 1 ? 1 : ((d) <= 4 ? 4 : ((d) <= 8 ? 8 : ((d) <= 16 ? 16 : 32))))
#define bytes_to_int32(x) (x)

void ReformatImage(char *image, long length, int bitsPerPixel, int clientOrder);
int ClientOrder(ClientPtr client);