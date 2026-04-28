#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

typedef struct {
    int type;
    void *target;
    char *string;
} XMLRI;

typedef struct {
    int type;
} SVG_Color;

typedef struct {
    int type;
    union {
        SVG_Color color;
        XMLRI iri;
    };
} SVG_Paint;

typedef struct {
    int colorIndexBits;
    void *sg;
    void *deferred_hrefs;
} GF_LASeRCodec;

#define GF_LSR_READ_INT(lsr, val, bits, name)
#define lsr_get_color(lsr, val, color)
#define lsr_read_any_uri(lsr, iri, name)
#define gf_node_unregister_iri(sg, iri)
#define gf_list_del_item(list, item)
#define lsr_read_byte_align_string(lsr, str, name)
#define gf_svg_get_system_paint_server_type(str) 0
#define gf_free(ptr) free(ptr)
#define lsr_read_extension(lsr, name)

enum {
    SVG_PAINT_INHERIT,
    SVG_PAINT_COLOR,
    SVG_PAINT_NONE,
    SVG_PAINT_URI
};

enum {
    SVG_COLOR_CURRENTCOLOR,
    XMLRI_STRING,
    XMLRI_ELEMENTID
};