#include <stdlib.h>

typedef struct sqlo_t sqlo_t;
typedef struct ST ST;
typedef struct op_table_t op_table_t;
typedef struct dbe_key_t dbe_key_t;
typedef struct sqlc_t sqlc_t;

#define DV_ARRAY_OF_POINTER 0
#define DV_LONG_INT 0
#define COL_DOTTED 0
#define STAR 0
#define SCO_THIS_QUAL 0
#define SCO_UNQUALIFIED 0
#define BOP_AND 0
#define GPF_T

#define DV_TYPE_OF(x) 0
#define BOX_ELEMENTS(x) 0
#define ST_P(x, y) 0
#define ST_COLUMN(x, y) 0

struct ST {
    union {
        struct {
            char *name;
            char *prefix;
        } col_ref;
        struct {
            ST *left;
            ST *right;
        } bin_exp;
    } _;
};

struct sqlc_t {
    void *sc_cc;
};

struct op_table_t {
    ST *ot_contains_exp;
    char *ot_prefix;
    struct {
        char *tb_name;
    } *ot_table;
    ST *ot_text_score;
    ST *ot_main_range_out;
    ST *ot_attr_range_out;
};

struct sqlo_t {
    sqlc_t *so_sc;
    int so_scope;
};

ST **sqlc_contains_args(ST *tree, int *ctype);
void sqlc_error(void *cc, const char *code, const char *format, ...);
void sqlc_new_error(void *cc, const char *code, const char *msg_code, const char *format, ...);
char *sqlo_spec_predicate_name(int ctype);
op_table_t *sco_is_defd(int scope, ST *arg, int qual, int flag);
int sqlo_is_contains_vdb_tb(sqlo_t *so, op_table_t *ot, int ctype, ST **args);
dbe_key_t *tb_text_key(void *table);
void sqlo_check_ft_offband(sqlo_t *so, op_table_t *ot, ST **args, char ctype);
ST *sqlo_virtual_col_crr(sqlo_t *so, op_table_t *ot, const char *name, int type, int flag);
void sqlo_xpath_col(sqlo_t *so, op_table_t *ot, ST **args, int arg, int ctype);