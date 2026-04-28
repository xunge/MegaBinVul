#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

typedef int gint;
typedef unsigned int guint;
typedef size_t gsize;

#define g_return_if_fail(expr) if (!(expr)) return
#define G_MAXINT INT_MAX
#define G_MAXSIZE SIZE_MAX
#define G_STRLOC ""
#define g_error(...) 
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct {
    int dummy;  // Placeholder for PangoGlyphInfo
} PangoGlyphInfo;

typedef struct {
    PangoGlyphInfo *glyphs;
    gint *log_clusters;
    gint num_glyphs;
    gint space;
} PangoGlyphString;

void* g_realloc(void *ptr, size_t size);