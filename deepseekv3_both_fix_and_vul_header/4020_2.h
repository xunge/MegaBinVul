#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char uchar;

#define DEBUG_printf(x)
#define DEBUG_puts(x)
#define SIZE_P 0
#define HD_ERROR_CONTENT_TOO_LARGE 1

static inline size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t src_len = strlen(src);
    if (size > 0) {
        size_t len = (src_len >= size) ? size - 1 : src_len;
        memcpy(dst, src, len);
        dst[len] = '\0';
    }
    return src_len;
}

typedef struct tree_s {
    int markup;
    struct tree_s *child;
    struct tree_s *next;
    struct tree_s *prev;
    uchar *data;
    float width;
    float height;
    int typeface;
    int style;
    int size;
    int superscript;
    int subscript;
    int underline;
    int strikethrough;
    uchar red;
    uchar green;
    uchar blue;
    int valignment;
    int halignment;
    struct tree_s *link;
} tree_t;

typedef struct render_s {
    int type;
    int page;
    float x;
    float y;
    float width;
    float height;
    float rgb[3];
    union {
        struct {
            int typeface;
            int style;
            float size;
            float spacing;
            float rgb[3];
            uchar *text;
        } text;
        uchar *link;
        uchar *image;
    } data;
} render_t;

enum {
    MARKUP_NONE,
    MARKUP_IMG,
    MARKUP_A,
    MARKUP_BR
};

enum {
    ALIGN_LEFT,
    ALIGN_CENTER,
    ALIGN_RIGHT,
    ALIGN_JUSTIFY,
    ALIGN_TOP,
    ALIGN_MIDDLE,
    ALIGN_BOTTOM
};

enum {
    RENDER_TEXT,
    RENDER_BOX,
    RENDER_IMAGE,
    RENDER_LINK
};

extern float _htmlSpacings[];
extern float _htmlSizes[];
extern float _htmlWidths[][4][256];
extern int _htmlUTF8;
extern int _htmlUnicode[256];
extern float PagePrintWidth;
extern float PagePrintLength;
extern int _htmlBrowserWidth;
extern int PSLevel;
extern int Verbosity;
extern int OverflowErrors;
extern int LinkStyle;
extern int Links;
extern float link_color[3];

extern tree_t *flatten_tree(tree_t *t);
extern void update_image_size(tree_t *t);
extern uchar *htmlGetVariable(tree_t *t, uchar *name);
extern void progress_show(const char *format, ...);
extern render_t *new_render(int page, int type, float x, float y, float width, float height, void *data);
extern void *image_find(char *src);
extern void progress_error(int code, const char *format, ...);
extern void add_link(uchar *id, int page, int y);
extern void progress_update(int percent);