#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

typedef int64_t lng;
typedef unsigned char bit;

#define type_int 0
#define type_lng 1
#define type_value 2
#define card_value 0
#define CARD_ATOM 0
#define F_AGGR 0
#define op_project 0
#define sql_sel 0
#define ddl_alter_seq 0
#define type_equal 0
#define FALSE 0
#define TRUE 1

#define lng_nil INT64_MIN
#define GDK_lng_min INT64_MIN
#define GDK_lng_max INT64_MAX
#define is_lng_nil(x) ((x) == lng_nil)
#define is_bit_nil(x) ((x) == 2)
#define llabs(x) ((x) < 0 ? -(x) : (x))
#define LLFMT "%" PRId64
#define SQLSTATE(x) ""

struct symbol {
    int type;
    union {
        lng l_val;
        void *sym;
    } data;
};

struct dlist {
    struct dlist *h;
    struct dlist *next;
    int type;
    union {
        int i_val;
        lng l_val;
        void *sym;
    } data;
};

struct sql_query {
    struct mvc *sql;
};

struct mvc {
    void *store;
    void *sa;
    int label;
};

struct sql_sequence {
    struct sql_schema *s;
    lng increment;
    lng minvalue;
    lng maxvalue;
    lng cacheinc;
    bit cycle;
    lng start;
};

struct sql_schema {
    struct {
        char *name;
    } base;
};

struct sql_rel {
    int op;
};

struct sql_exp {
    int card;
};

struct sql_subtype {
};

struct sql_subfunc {
};

struct exp_kind {
    int type;
    int card;
    bool flag;
};

typedef struct sql_rel sql_rel;
typedef struct sql_query sql_query;
typedef struct dlist dlist;
typedef struct sql_subtype sql_subtype;
typedef struct symbol symbol;
typedef struct mvc mvc;
typedef struct sql_sequence sql_sequence;
typedef struct sql_exp sql_exp;
typedef struct sql_subfunc sql_subfunc;
typedef struct exp_kind exp_kind;

static char *get_string_global_var(struct mvc *sql, const char *name) { return NULL; }
static struct sql_sequence *find_sequence_on_scope(struct mvc *sql, char *sname, char *name, const char *msg) { return NULL; }
static int mvc_schema_privs(struct mvc *sql, void *s) { return 0; }
static struct sql_rel *sql_error(struct mvc *sql, int code, const char *msg, ...) { return NULL; }
static struct sql_sequence *create_sql_sequence(void *store, void *sa, void *s, char *name, lng start, lng min, lng max, lng inc, lng cache, bit cycle) { return NULL; }
static struct sql_exp *exp_atom_lng(void *sa, lng val) { return NULL; }
static struct sql_exp *rel_value_exp2(struct sql_query *query, struct sql_rel **r, void *sym, int sel, struct exp_kind ek) { return NULL; }
static struct sql_exp *exp_check_type(struct mvc *sql, struct sql_subtype *tpe, struct sql_rel *r, struct sql_exp *val, int type) { return NULL; }
static void exp_label(void *sa, struct sql_exp *val, int label) {}
static struct sql_exp *rel_project_add_exp(struct mvc *sql, struct sql_rel *r, struct sql_exp *val) { return NULL; }
static struct sql_subfunc *sql_bind_func(struct mvc *sql, const char *sys, const char *name, void *subtype, void *arg, int flag, bool b) { return NULL; }
static struct sql_exp *exp_aggr1(void *sa, struct sql_exp *val, struct sql_subfunc *func, int a, int b, int card, int has_nil) { return NULL; }
static struct sql_rel *rel_seq(void *sa, int type, char *name, struct sql_sequence *seq, struct sql_rel *r, struct sql_exp *val) { return NULL; }
static struct sql_subtype *sql_bind_localtype(const char *name) { return NULL; }
static char *qname_schema(struct dlist *qname) { return NULL; }
static char *qname_schema_object(struct dlist *qname) { return NULL; }
static int has_nil(struct sql_exp *val) { return 0; }
static void *exp_subtype(struct sql_exp *val) { return NULL; }