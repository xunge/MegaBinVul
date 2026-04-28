#include <stdint.h>
#include <stdbool.h>

#define TAG "GlyphCache"
#define PRIu32 "u"
#define TRUE true
#define FALSE false

typedef unsigned int UINT32;
typedef bool BOOL;

typedef struct rdpGlyph rdpGlyph;
typedef struct rdpGlyphCache rdpGlyphCache;

struct rdpGlyph
{
    void (*Free)(void* context, rdpGlyph* glyph);
};

struct rdpGlyphCache
{
    struct
    {
        UINT32 number;
        rdpGlyph** entries;
    } glyphCache[10];
    void* log;
    void* context;
};

void WLog_ERR(const char* tag, const char* format, ...);
void WLog_Print(void* log, int level, const char* format, ...);

#define WLOG_DEBUG 0