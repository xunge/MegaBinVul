#include <stdlib.h>
#include <assert.h>

typedef struct sql_rel sql_rel;
typedef struct mvc mvc;
typedef struct sql_idx sql_idx;
typedef struct sql_exp sql_exp;
typedef struct sql_subtype sql_subtype;
typedef struct sql_subfunc sql_subfunc;
typedef struct sql_kc sql_kc;
typedef struct sa sa;
typedef struct node node;
typedef struct list list;

enum optype {
    op_table,
    op_project
};

enum idx_type {
    hash_idx,
    oph_idx
};

#define is_project(op) ((op) == op_project)
#define non_updatable_index(type) 0

struct sql_rel {
    enum optype op;
    list *exps;
    sql_rel *r;
};

struct sql_idx {
    char *name;
    enum idx_type type;
    list *columns;
    struct {
        char *name;
    } base;
};

struct list {
    node *h;
    int length;
};

struct node {
    void *data;
    node *next;
};

struct sa {
    // implementation defined
};

#define sa_strconcat(sa, ...) NULL
#define new_exp_list(sa) NULL
#define list_append(list, item) 
#define list_fetch(list, index) NULL
#define list_length(list) 0
#define append(list, item) 
#define exp_label(sa, exp, label) NULL
#define exp_atom_lng(sa, val) NULL
#define exp_ref(sql, exp) NULL
#define exp_atom_int(sa, val) NULL
#define exp_op(sa, exps, func) NULL
#define exp_binop(sa, left, right, func) NULL
#define exp_unop(sa, exp, func) NULL
#define exp_setname(sa, exp, alias, name) 
#define rel_project(sa, rel, proj) NULL
#define rel_projections(sql, rel, name, flag1, flag2) NULL
#define sql_bind_localtype(name) NULL
#define sql_bind_func_result(sql, schema, name, type, flag, ret, nargs, ...) NULL