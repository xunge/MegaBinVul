#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct mvc mvc;

typedef struct list {
    struct node *h;
} list;

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef struct sql_rel {
    int op;
    int flag;
    void *l;
    void *r;
    list *exps;
} sql_rel;

typedef struct sql_table {
    void *base;
} sql_table;

typedef struct sql_exp {
    int type;
    const char *r;
    struct sql_subfunc *f;
} sql_exp;

typedef struct sql_idx {
    void *base;
} sql_idx;

typedef struct sql_column {
    void *base;
} sql_column;

typedef struct sql_subfunc {
    struct {
        void *base;
    } *func;
} sql_subfunc;

enum operator_type {
    op_basetable,
    op_table,
    op_join,
    op_left,
    op_right,
    op_full,
    op_semi,
    op_anti,
    op_union,
    op_except,
    op_inter,
    op_insert,
    op_update,
    op_delete,
    op_merge,
    op_project,
    op_select,
    op_groupby,
    op_topn,
    op_sample,
    op_truncate,
    op_ddl
};

enum ddl_flag {
    ddl_output,
    ddl_create_seq,
    ddl_alter_seq,
    ddl_alter_table,
    ddl_create_table,
    ddl_create_view,
    ddl_list,
    ddl_exception
};

#define SQLSTATE(s) "42000"
#define TID "%TID%"
#define IS_TABLE_PROD_FUNC(f) (0)
#define TABLE_FROM_RELATION (0)

static int mvc_highwater(mvc *sql) { return 0; }
static int sql_error(mvc *sql, int code, const char *message) { return -1; }
static int rel_is_ref(sql_rel *r) { return 0; }
static int refs_find_rel(list *refs, sql_rel *r) { return 0; }
static int is_func(int type) { return 0; }
static sql_idx *find_sql_idx(sql_table *t, const char *name) { return NULL; }
static sql_column *find_sql_column(sql_table *t, const char *name) { return NULL; }
static void cond_append(list *l, void *data) {}
static int exps_deps(mvc *sql, list *exps, list *refs, list *l) { return 0; }
static int is_base(int op) { return 0; }
static int is_simple_project(int op) { return 0; }
static int is_groupby(int op) { return 0; }
static void list_append(list *l, void *data) {}