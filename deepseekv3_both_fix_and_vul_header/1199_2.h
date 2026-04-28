#include <stdlib.h>
#include <stdbool.h>

typedef struct sql_exp {
    int card;
    char *name;
    bool has_label;
} sql_exp;

typedef struct sql_query {
    struct mvc *sql;
} sql_query;

typedef struct sql_rel {
    int op;
    struct sql_rel *l;
    struct list *exps;
    int card;
    bool processed;
} sql_rel;

typedef struct symbol symbol;
typedef struct mvc mvc;

typedef struct node {
    struct node *next;
    sql_exp *data;
} node;

typedef struct list {
    node *h;
} list;

typedef enum {
    type_value
} exp_type;

typedef enum {
    card_column
} exp_card;

typedef struct {
    exp_type type_value;
    exp_card card_column;
    bool FALSE;
} exp_kind;

#define FALSE false
#define ERR_GROUPBY 1
#define SQLSTATE(code) #code

bool is_simple_project(int op);
bool is_processed(sql_rel *r);
sql_exp *rel_value_exp(sql_query *query, sql_rel **r, symbol *column_r, int f, exp_kind ek);
bool is_project(int op);
sql_exp *exps_any_match(list *exps, sql_exp *e);
sql_exp *exp_ref(mvc *sql, sql_exp *found);
sql_exp *sql_error(mvc *sql, int code, const char *msg, ...);
sql_exp *rel_project_add_exp(mvc *sql, sql_rel *p, sql_exp *e);
const char *exp_name(sql_exp *ee);
bool has_label(sql_exp *ee);
sql_exp *exps_find_exp(list *exps, sql_exp *e);
void append(list *exps, sql_exp *e);