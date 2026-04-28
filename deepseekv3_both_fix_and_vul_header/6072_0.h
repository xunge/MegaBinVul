#include <stdlib.h>
#include <assert.h>

typedef struct ASS_Track ASS_Track;
typedef struct ASS_Library ASS_Library;
typedef struct ParserPriv ParserPriv;

struct ASS_Library {
    int extract_fonts;
    void *library;
};

struct ParserPriv {
    unsigned char *fontdata;
    size_t fontdata_used;
    char *fontname;
};

struct ASS_Track {
    ASS_Library *library;
    ParserPriv *parser_priv;
};

unsigned char *decode_chars(unsigned char *p, unsigned char *q, int n);
void ass_msg(void *library, int level, const char *fmt, ...);
void ass_add_font(void *library, const char *name, char *data, size_t size);
void reset_embedded_font_parsing(ParserPriv *priv);

#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define MSGL_V 1
#define MSGL_ERR 2