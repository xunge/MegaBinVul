#include <stdio.h>

typedef struct tree_node tree_node_t;
typedef int ELM_ID_t;

struct elemento {
    ELM_ID_t elm_id;
    tree_node_t *hijo;
    char *name;
};

struct tree_node {
    int tipo;
    union {
        struct elemento elemento;
        void *other;
    } cont;
    tree_node_t *padre;
    tree_node_t *inicio;
};

#define ELM_PTR(node) (node->cont.elemento)
#define ELM_ID(node) (node->cont.elemento.elm_id)
#define Node_element 1
#define LINK_MODE_CHILD 0

extern tree_node_t *actual_element;
extern tree_node_t *document;
extern int doctype;
extern int new_place_recovery_on;
extern tree_node_t *new_place_recovery_elm;
extern tree_node_t *new_place_recovery_father;

#define ELMID_OL 0
#define ELMID_UL 1
#define ELMID_LI 2
#define ELMID_TABLE 3
#define ELMID_THEAD 4
#define ELMID_TBODY 5
#define ELMID_TR 6
#define ELMID_TH 7
#define ELMID_TD 8
#define ELMID_HEAD 9
#define ELMID_BODY 10
#define ELMID_FRAMESET 11
#define ELMID_P 12
#define ELMID_HTML 13
#define ELMID_STYLE 14

extern int dtd_can_be_child(ELM_ID_t child, ELM_ID_t parent, int doctype);
extern tree_node_t *err_aux_insert_elm(ELM_ID_t elm_id, void *arg, int flag);
extern void elm_close(tree_node_t *node);
extern int err_html_struct(tree_node_t *doc, ELM_ID_t elm_id);
extern tree_node_t *new_tree_node(int type);
extern void link_node(tree_node_t *node, tree_node_t *parent, int mode);
extern tree_node_t *tree_search_elm_child(tree_node_t *parent, ELM_ID_t elm_id);

#define EPRINTF1(fmt, arg) printf(fmt, arg)
#define DEBUG(msg) printf("%s\n", msg)
#define INFORM(msg) printf("%s\n", msg)