#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define NLOCALGLYPH 16

typedef unsigned char CARD8;
typedef unsigned int CARD32;
typedef void *pointer;
typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef struct _DrawableRec {
    int dummy;
} DrawableRec;

typedef struct _ClientRec {
    char *requestBuffer;
    unsigned int requestBufferLength;
    unsigned int req_len;
    CARD32 errorValue;
} *ClientPtr;

typedef struct _FormatRec {
    int format;
    int depth;
} *FormatPtr;

typedef struct _GlyphSetRec {
    FormatPtr format;
    int fdepth;
} *GlyphSetPtr;

typedef struct _PictureRec *PicturePtr;

typedef struct _GlyphRec {
    unsigned char sha1[20];
    PicturePtr pictures[1];
} GlyphRec, *GlyphPtr;

typedef struct _PixmapRec {
    DrawableRec drawable;
} *PixmapPtr;

typedef struct _ScreenRec {
    PixmapPtr (*CreatePixmap)(struct _ScreenRec *, int, int, int, int);
    void (*DestroyPixmap)(PixmapPtr);
} *ScreenPtr;

typedef struct {
    int width;
    int height;
} xGlyphInfo;

typedef struct {
    CARD32 id;
    GlyphPtr glyph;
    unsigned char sha1[20];
    Bool found;
} GlyphNewRec, *GlyphNewPtr;

typedef struct {
    CARD32 glyphset;
    CARD32 nglyphs;
} xRenderAddGlyphsReq;

typedef struct {
    int numScreens;
    ScreenPtr *screens;
} ScreenInfo;

extern ScreenInfo screenInfo;
extern ClientPtr serverClient;

#define GlyphSetType 1
#define DixAddAccess 2
#define BadAlloc 1
#define BadLength 2
#define Success 0
#define DeletedGlyph ((GlyphPtr)1)
#define None 0
#define PictOpSrc 1
#define CPComponentAlpha 1
#define CREATE_PIXMAP_USAGE_GLYPH_PICTURE 1

#define REQUEST(x) x *stuff = (x *)client->requestBuffer
#define REQUEST_AT_LEAST_SIZE(x) \
    if (client->requestBufferLength < sizeof(x)) return BadLength

static int dixLookupResourceByType(pointer *, CARD32, int, ClientPtr, int);
static int NeedsComponent(int);
static size_t PixmapBytePad(int, int);
static int HashGlyph(xGlyphInfo *, CARD8 *, unsigned int, unsigned char[20]);
static GlyphPtr FindGlyphByHash(unsigned char[20], int);
static GlyphPtr AllocateGlyph(xGlyphInfo *, int);
static PixmapPtr GetScratchPixmapHeader(ScreenPtr, int, int, int, int, int, CARD8 *);
static PicturePtr CreatePicture(CARD32, void *, void *, CARD32, void *, ClientPtr, int *);
static void FreePicture(pointer, CARD32);
static void FreeScratchPixmapHeader(PixmapPtr);
static Bool ResizeGlyphSet(GlyphSetPtr, int);
static void AddGlyph(GlyphSetPtr, GlyphPtr, CARD32);
static void CompositePicture(int, PicturePtr, PicturePtr, PicturePtr, int, int, int, int, int, int, int, int);
static PicturePtr *GlyphPicture(GlyphPtr);