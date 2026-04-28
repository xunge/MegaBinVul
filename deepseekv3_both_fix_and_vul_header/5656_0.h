#include <stdbool.h>

class GlyphBuffer;

class HarfBuzzShaper {
public:
    bool shape(GlyphBuffer* glyphBuffer);
    bool createHarfBuzzRuns();
    bool shapeHarfBuzzRuns();
    bool fillGlyphBuffer(GlyphBuffer* glyphBuffer);
    int m_totalWidth;
};