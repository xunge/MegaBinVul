#include <stdint.h>
#include <stddef.h>

#define XCURSOR_IMAGE_MAX_SIZE 0x7fff

typedef struct XcursorFile XcursorFile;
typedef struct XcursorFileHeader XcursorFileHeader;

typedef struct {
    uint32_t version;
    uint32_t subtype;
} XcursorChunkHeader;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t xhot;
    uint32_t yhot;
    uint32_t delay;
} XcursorImageHead;

typedef struct XcursorImage {
    uint32_t width;
    uint32_t height;
    uint32_t xhot;
    uint32_t yhot;
    uint32_t delay;
    uint32_t version;
    uint32_t size;
    uint32_t *pixels;
} XcursorImage;

typedef uint32_t XcursorPixel;

static int _XcursorFileReadChunkHeader(XcursorFile *file, XcursorFileHeader *fileHeader, int toc, XcursorChunkHeader *chunkHeader);
static int _XcursorReadUInt(XcursorFile *file, uint32_t *u);
static XcursorImage *XcursorImageCreate(int width, int height);
static void XcursorImageDestroy(XcursorImage *image);