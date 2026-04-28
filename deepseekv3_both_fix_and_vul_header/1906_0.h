#include <stdlib.h>

typedef struct GF_SceneLoader GF_SceneLoader;
typedef struct GF_XMTParser GF_XMTParser;
typedef struct XMTNodeStack XMTNodeStack;
typedef struct GF_Descriptor GF_Descriptor;

struct XMTNodeStack {
    void *node;
};

struct GF_SceneLoader {
    void *loader_priv;
};

struct GF_XMTParser {
    void *nodes;
    void *x3d_root;
    void *descriptors;
    void *def_nodes;
    void *peeked_nodes;
    void *inserted_routes;
    void *unresolved_routes;
    void *od_links;
    void *esd_links;
    void *sax_parser;
    void *script_to_load;
};

void gf_list_rem_last(void *list);
void *gf_list_last(void *list);
void gf_node_register(void *node, void *ptr);
void gf_node_unregister(void *node, void *ptr);
void gf_free(void *ptr);
void gf_list_del(void *list);
unsigned int gf_list_count(void *list);
void *gf_list_get(void *list, unsigned int index);
void gf_odf_desc_del(void *desc);
void gf_xml_sax_del(void *sax_parser);