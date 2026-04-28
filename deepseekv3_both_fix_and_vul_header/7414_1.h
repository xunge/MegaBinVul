#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 id;
} SVG_SAFExternalStream;

typedef struct {
    u32 flags;
} GF_Load;

typedef struct {
    GF_Load *load;
} GF_SVG_Parser;

typedef struct {
    char *string;
    u32 lsr_stream_id;
    int type;
} XMLRI;

typedef struct GF_DOMAttribute {
    void *data;
    int data_type;
    u32 tag;
    struct GF_DOMAttribute *next;
} GF_DOMAttribute;

typedef struct {
    int type;
} GF_DOMText;

typedef struct {
    GF_DOMAttribute *attributes;
    void *scenegraph;
} GF_DOMNode;

typedef struct {
    GF_DOMNode *sgprivate;
} GF_Node;

typedef enum {
    TAG_SVG_image,
    TAG_SVG_video,
    TAG_SVG_audio,
    TAG_SVG_script,
    TAG_XLINK_ATT_href
} GF_SVG_Tag;

typedef enum {
    XMLRI_STRING,
    XMLRI_STREAMID
} XMLRI_Type;

typedef enum {
    GF_OK,
    GF_ERR
} GF_Err;

enum {
    GF_DOM_TEXT_CDATA
};

#define GF_SM_LOAD_EMBEDS_RES (1 << 0)

static SVG_SAFExternalStream *svg_saf_get_stream(GF_SVG_Parser *parser, int a, char *b) { return NULL; }
static int strnicmp(const char *s1, const char *s2, size_t n) { return 0; }
static int stricmp(const char *s1, const char *s2) { return 0; }
static void gf_free(void *ptr) {}
static void *gf_malloc(size_t size) { return NULL; }
static GF_DOMText *gf_dom_add_text_node(GF_Node *elt, char *buffer) { return NULL; }
static void gf_svg_delete_attribute_value(int type, void *data, void *scenegraph) {}
static GF_Err gf_file_load_data(char *path, u8 **buffer, u32 *size) { return GF_OK; }
static u64 gf_base64_encode(char *in, u32 in_size, char *out, u32 out_size) { return 0; }
static u32 gf_node_get_tag(GF_Node *node) { return 0; }