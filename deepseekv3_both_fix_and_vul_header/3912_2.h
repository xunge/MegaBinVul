#include <stdlib.h>

typedef enum idx_type {
    join_idx
} idx_type;

typedef struct sql_rel {
    struct sql_rel *r;
    struct sql_rel *l;
    int op;
    unsigned int card;
    unsigned int flag;
} sql_rel;

typedef struct mvc {
    void *sa;
} mvc;

typedef struct sql_table {
    struct ol *idxs;
} sql_table;

typedef struct sql_idx {
    idx_type type;
} sql_idx;

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef struct ol {
    unsigned int length;
    struct node *first;
} ol;

enum {
    op_insert,
    UPD_COMP
};

extern int ol_length(ol *);
extern node *ol_first_node(ol *);
extern sql_rel *rel_label(mvc *, sql_rel *, int);
extern int hash_index(idx_type);
extern int non_updatable_index(idx_type);
extern sql_rel *rel_insert_hash_idx(mvc *, const char *, sql_idx *, sql_rel *);
extern sql_rel *rel_insert_join_idx(mvc *, const char *, sql_idx *, sql_rel *);
extern sql_rel *rel_create(void *);
extern sql_rel *rel_dup(sql_rel *);