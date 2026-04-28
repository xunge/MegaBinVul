#include <stddef.h>

typedef struct ST ST;
typedef long ptrlong;
typedef void* caddr_t;

typedef struct {
    void *sc_cc;
} sql_comp_t;

enum {
    TABLE_EXP,
    DERIVED_TABLE,
    SELECT_STMT
};

struct ST {
    union {
        struct {
            ST *table_exp;
            ST **order_by;
            ptrlong flags;
            caddr_t *opts;
        } table_exp;
        struct {
            ST *table_exp;
        } select_stmt;
    } _;
};

ST *sqlp_union_tree_select(ST *tree);
ST *sqlp_union_tree_right(ST *tree);
void sqlc_new_error(void *sc_cc, const char *code1, const char *code2, const char *msg);
ST *sqlp_infoschema_redirect(ST *arg);
ST *t_listst(int count, ...);
ST *t_list(int count, ...);
char *t_box_string(const char *str);
ST **sqlc_selection_names(ST *left);