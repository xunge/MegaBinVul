#include <stdlib.h>

typedef struct sqlo_t sqlo_t;
typedef struct data_source_t data_source_t;
typedef struct df_elt_t df_elt_t;
typedef void* dk_set_t;
typedef struct dpipe_node_t dpipe_node_t;
typedef struct sql_comp_t sql_comp_t;
typedef struct op_table_t op_table_t;
typedef struct state_slot_t state_slot_t;
typedef struct fun_ref_node_t fun_ref_node_t;
typedef struct ST ST;

struct sqlo_t {
    sql_comp_t *so_sc;
};

struct df_elt_t {
    union {
        struct {
            op_table_t *ot;
        } sub;
    } _;
    state_slot_t *dfe_ssl;
};

struct sql_comp_t {
    dk_set_t sc_fun_ref_temps;
    dk_set_t sc_fun_ref_defaults;
    dk_set_t sc_fun_ref_default_ssls;
    fun_ref_node_t *sc_fref;
};

struct op_table_t {
    dk_set_t ot_fun_refs;
};

struct dpipe_node_t {
    struct {
        void *src_after_code;
    } src_gen;
};

struct fun_ref_node_t {
    dk_set_t fnr_default_values;
    dk_set_t fnr_default_ssls;
    dk_set_t fnr_temp_slots;
    struct {
        void *src_after_code;
    } src_gen;
};

struct data_source_t {
    dk_set_t src_continuations;
    dk_set_t src_after_code;
    struct {
        dk_set_t qr_nodes;
    } *src_query;
};

#define SQL_NODE_INIT(type, var, input, free) type *var = malloc(sizeof(type))
#define DO_SET(type, var, set)
#define END_DO_SET()

data_source_t *sql_node_last(data_source_t *head);
void *dk_set_cons(void *car, void *cdr);
void dk_set_delete(dk_set_t *set, void *item);
void dk_set_ins_before(dk_set_t *set, void *before, void *item);
dk_set_t dk_set_nreverse(dk_set_t list);
state_slot_t *select_ref_generate(sql_comp_t *sc, fun_ref_node_t *fref, dk_set_t *post_fref_code, dk_set_t *cum_code, int *ign);
df_elt_t *sqlo_df(sqlo_t *so, fun_ref_node_t *fref);
dpipe_node_t *sqlg_pre_code_dpipe(sqlo_t *so, dk_set_t *cum_code, void *arg);
void *code_to_cv(sql_comp_t *sc, dk_set_t code);
void sqlg_place_fref(sql_comp_t *sc, data_source_t **head, fun_ref_node_t *fref, df_elt_t *tb_dfe);