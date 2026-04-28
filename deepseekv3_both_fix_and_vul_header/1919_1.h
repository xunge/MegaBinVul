#include <stdio.h>
#include <stdlib.h>

enum {
    ELMID_HEAD,
    ELMID_BODY,
    ELMID_FRAMESET,
    ELMID_HTML,
    ELMID_TITLE
};

enum {
    XHTML_FRAMESET,
    Node_element
};

typedef struct tree_node_t {
    int tipo;
    struct tree_node_t *padre;
} tree_node_t;

typedef struct document_t {
    tree_node_t *inicio;
} document_t;

extern int doctype;
extern tree_node_t *actual_element;

tree_node_t *tree_search_elm_child(tree_node_t *node, int elm_id);
tree_node_t *err_aux_insert_elm(int elm_id, void *data, int size);
void elm_close(tree_node_t *node);
int dtd_can_be_child(int elm_id, int parent_id, int doctype);

#define DEBUG(x)
#define EPRINTF(...)