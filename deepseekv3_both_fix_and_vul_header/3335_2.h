#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>
#include <limits.h>

typedef int Bool;
#define FALSE 0
#define TRUE 1

typedef uint32_t CARD32;
typedef unsigned long Atom;

typedef struct _FontFile *FontFilePtr;

typedef struct {
    unsigned int firstRow;
    unsigned int lastRow;
    unsigned int firstCol;
    unsigned int lastCol;
    Bool allExist;
} FontInfo;

typedef struct _Font {
    void *fontPrivate;
    FontInfo info;
} *FontPtr;

typedef struct {
    int digitWidths;
    int digitCount;
    int exHeight;
} bdfFileState;

typedef struct _CharInfoRec {
    struct {
        int leftSideBearing;
        int rightSideBearing;
        int ascent;
        int descent;
        int characterWidth;
        unsigned int attributes;
    } metrics;
    void *bits;
} CharInfoRec, *CharInfoPtr;

typedef struct _BitmapFontRec {
    void *fontPrivate;
    void *bitmapExtra;
    CharInfoPtr *metrics;
    int num_chars;
    CharInfoPtr **encoding;
} *BitmapFontPtr;

typedef struct _BitmapExtraRec {
    CARD32 *bitmapsSizes;
    Atom *glyphNames;
    int *sWidths;
} *BitmapExtraPtr;

#define BDFLINELEN 1024
#define GLYPHPADOPTIONS 4
#define MAXENCODING 0xFFFF
#define INDICES 256
#define BITMAP_FONT_SEGMENT_SIZE 256
#define NUM_SEGMENTS(n) (((n) + BITMAP_FONT_SEGMENT_SIZE - 1) / BITMAP_FONT_SEGMENT_SIZE)
#define SEGMENT_MAJOR(i) ((i) / BITMAP_FONT_SEGMENT_SIZE)
#define ACCESSENCODINGL(e,i) ((e)[SEGMENT_MAJOR(i)][(i) % BITMAP_FONT_SEGMENT_SIZE])

static unsigned char *bdfGetLine(FontFilePtr file, unsigned char *buf, int len);
static int bdfIsPrefix(unsigned char *line, const char *prefix);
static void bdfError(const char *fmt, ...);
static void bdfWarning(const char *fmt, ...);
static Atom bdfForceMakeAtom(const char *name, void *unused);
static unsigned int bdfHexByte(unsigned char *p);
static void bdfReadBitmap(CharInfoPtr ci, FontFilePtr file, int bit, int byte, int glyph, int scan, CARD32 *sizes);
static void bdfSkipBitmap(FontFilePtr file, int rows);