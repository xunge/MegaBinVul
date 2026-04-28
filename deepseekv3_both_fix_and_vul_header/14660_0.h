#include <stdlib.h>
#include <assert.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int xMin;
    int xMax;
} BBox;

typedef struct {
    Point pos;
    BBox bbox;
    int symbol;
    int linebreak;
    int skip;
} GlyphInfo;

typedef struct {
    int offset;
    int len;
    double asc;
    double desc;
} LineInfo;

typedef struct {
    GlyphInfo *glyphs;
    LineInfo *lines;
    int length;
    int n_lines;
    int max_lines;
} TextInfo;

typedef struct {
    int wrap_style;
} RenderState;

typedef struct {
    double line_spacing;
} RenderSettings;

typedef struct {
    void *library;
    TextInfo text_info;
    RenderState state;
    RenderSettings settings;
} ASS_Renderer;

enum {
    MSGL_DBG2
};

void ass_msg(void *library, int level, const char *fmt, ...);
double d6_to_double(int value);
int double_to_d6(double value);
void measure_text(ASS_Renderer *render_priv);
void trim_whitespace(ASS_Renderer *render_priv);