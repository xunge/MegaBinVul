#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node tree_node_t;

struct tree_node {
    int tipo;
    union {
        struct {
            tree_node_t *hijo;
        } elemento;
    } cont;
    tree_node_t *sig;
    int contenttype[1];
    int contentspec[1];
    char *name;
};

#define DEBUG(msg)
#define EPRINTF1(fmt, arg)
#define ELM_PTR(node) (*(node))
#define ELM_ID(node) (0)
#define Node_element (0)
#define CONTTYPE_CHILDREN (0)
#define EXIT(msg) exit(1)
#define WARNING(msg)
#define doctype (0)

extern int dtd_is_child_valid(int contentspec, int *content, int num);
extern int err_content_invalid(tree_node_t *nodo, int *content, int num);