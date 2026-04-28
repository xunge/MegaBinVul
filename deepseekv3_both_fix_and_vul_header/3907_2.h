#include <stdlib.h>
#include <string.h>

typedef struct sql_rel sql_rel;
typedef struct sql_exp sql_exp;
typedef struct list list;
typedef struct node node;
typedef struct sa sa;
typedef struct mvc mvc;

struct mvc {
    sa *sa;
};

struct sql_rel {
    int card;
    sql_rel *l;
    sql_rel *r;
    list *exps;
    int nrcols;
    int op;
    int grouped;
};

struct sql_exp {
    int card;
    const char *relname;
    const char *name;
};

struct node {
    void *data;
    struct node *next;
};

struct list {
    struct node *h;
    struct node *t;
    int cnt;
};

enum {
    CARD_ATOM,
    CARD_AGGR
};

enum {
    op_groupby
};

sql_rel *rel_create(sa *sa);
void rel_destroy(sql_rel *rel);
list *new_exp_list(sa *sa);
list *sa_list(sa *sa);
int list_length(list *l);
void list_append(list *l, void *data);
sql_exp *exps_find_exp(list *l, sql_exp *e);
const char *exp_relname(sql_exp *e);
const char *exp_name(sql_exp *e);
sql_exp *exp_ref(mvc *sql, sql_exp *e);
sql_exp *exp_propagate(sa *sa, sql_exp *ne, sql_exp *e);
void append(list *l, void *data);

#define MIN(a, b) ((a) < (b) ? (a) : (b))