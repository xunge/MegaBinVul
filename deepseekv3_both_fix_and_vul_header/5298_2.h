#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct GF_SceneLoaderContext {
    int is_pixel_metrics;
} GF_SceneLoaderContext;

typedef struct GF_SceneLoader {
    int type;
    GF_SceneLoaderContext* ctx;
    void* loader_priv;
} GF_SceneLoader;

typedef struct GF_XMLParser GF_XMLParser;

typedef struct GF_XMTParser {
    void *nodes;
    void *descriptors;
    void *od_links;
    void *esd_links;
    void *def_nodes;
    void *peeked_nodes;
    void *inserted_routes;
    void *unresolved_routes;
    GF_XMLParser *sax_parser;
    GF_SceneLoader *load;
} GF_XMTParser;

void* gf_list_new();
GF_XMLParser* gf_xml_sax_new(void*, void*, void*, void*);
void xmt_node_start(void*, const char*, const char**);
void xmt_node_end(void*, const char*);
void xmt_text_content(void*, const char*, u32);

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_SM_LOAD_XSR 0