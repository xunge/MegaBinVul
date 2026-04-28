#include <stdint.h>
#include <stddef.h>

typedef struct XcursorFile XcursorFile;
typedef struct XcursorFileHeader XcursorFileHeader;
typedef struct XcursorChunkHeader XcursorChunkHeader;
typedef struct XcursorImage XcursorImage;
typedef uint32_t XcursorPixel;

#define XCURSOR_IMAGE_MAX_SIZE 0x7fff

struct XcursorImage {
    uint32_t width;
    uint32_t height;
    uint32_t xhot;
    uint32_t yhot;
    uint32_t delay;
    uint32_t version;
    uint32_t size;
    XcursorPixel *pixels;
};

struct XcursorChunkHeader {
    uint32_t header;
    uint32_t type;
    uint32_t subtype;
    uint32_t version;
};

static int _XcursorFileReadChunkHeader(XcursorFile *file, XcursorFileHeader *fileHeader, int toc, XcursorChunkHeader *chunkHeader);
static int _XcursorReadUInt(XcursorFile *file, uint32_t *u);
static XcursorImage *XcursorImageCreate(uint32_t width, uint32_t height);
static void XcursorImageDestroy(XcursorImage *image);