#include <stddef.h>

typedef struct sqlo_t sqlo_t;
typedef struct df_elt_t df_elt_t;
typedef struct op_table_t op_table_t;

struct op_table_t {
    void *ot_oby_ots;
    int ot_is_outer;
};

struct df_elt_t {
    int dfe_type;
    df_elt_t *dfe_next;
    union {
        struct {
            int hash_role;
            int is_unique;
            int is_oby_order;
            op_table_t *ot;
        } table;
    } _;
};

struct sqlo_t {
    op_table_t *so_this_dt;
};

#define DFE_TABLE 1
#define DFE_DT 2
#define HR_REF 1

int dk_set_length(void *set);