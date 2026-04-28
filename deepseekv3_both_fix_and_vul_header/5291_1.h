#include <stdlib.h>

typedef enum {
    GF_OK = 0,
    GF_ERR
} GF_Err;

typedef enum {
    XMLRI_ELEMENTID,
    XMLRI_STRING
} XMLRI_Type;

typedef struct _XMLRI {
    XMLRI_Type type;
    void *target;
    char *string;
} XMLRI;

typedef struct _GF_Node GF_Node;

typedef struct {
    unsigned int flags;
    char *localPath;
    char *fileName;
} GF_SM_Load;

#define GF_SM_LOAD_FOR_PLAYBACK (1 << 0)

typedef struct _GF_SVG_Parser {
    GF_SM_Load *load;
    void *defered_hrefs;
} GF_SVG_Parser;

void svg_process_media_href(GF_SVG_Parser *parser, GF_Node *elt, XMLRI *iri);
void svg_report(GF_SVG_Parser *parser, GF_Err e, const char *msg);
GF_Err gf_node_store_embedded_data(XMLRI *iri, const char *localPath, const char *fileName);
void gf_list_add(void *list, void *item);