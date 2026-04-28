#include <stdlib.h>

struct GfxState;
class GooString {
public:
    int getLength();
};

struct cairo_glyph_t {
    unsigned long index;
    double x;
    double y;
};

class CairoOutputDev {
public:
    void beginString(GfxState *state, GooString *s);
    cairo_glyph_t *glyphs;
    int glyphCount;
};

extern int needFontUpdate;
extern void *currentFont;

void updateFont(GfxState *state);
void *gmalloc(size_t size);
void *gmallocn(int n, size_t size);