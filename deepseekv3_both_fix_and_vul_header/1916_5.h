#include <stdio.h>
#include <string.h>

#define ELM_NAME_LEN 100
#define ST_PARSING 1
#define ST_END 2
#define Node_element 1

typedef char xchar;

typedef struct tree_node_t {
    int tipo;
    int ELM_ID;
    struct tree_node_t *padre;
    struct tree_node_t *father;
} tree_node_t;

#define ELM_ID(n) ((n)->ELM_ID)
#define DEBUG(msg) fprintf(stderr, "%s", msg);
#define INFORM(msg) fprintf(stderr, "%s", msg);
#define EPRINTF1(fmt, arg) fprintf(stderr, fmt, arg)

extern int state;
extern tree_node_t *actual_element;
extern int new_place_recovery_on;
extern tree_node_t *new_place_recovery_elm;
extern tree_node_t *new_place_recovery_father;

int dtd_elm_search(const xchar *name);
int err_elm_desconocido(const xchar *name);
void elm_close(tree_node_t *node);
void xtolower(xchar *dest, const xchar *src, int len);