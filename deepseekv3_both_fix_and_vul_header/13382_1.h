#include <stddef.h>

typedef unsigned char caddr_t;
typedef struct setp_node_t setp_node_t;
typedef struct index_tree_t index_tree_t;
typedef struct hash_area_t hash_area_t;
typedef struct data_col_t data_col_t;
typedef struct chash_t chash_t;
typedef struct query_instance_t {
    int qi_set;
} query_instance_t;
typedef struct state_slot_t state_slot_t;
typedef struct mem_pool_t mem_pool_t;
typedef struct hash_item_t hash_item_t;
typedef struct sqt_t sqt_t;

#define BOX_ELEMENTS(arr) (sizeof(arr)/sizeof((arr)[0]))
#define QST_BOX(type, inst, index) ((type)((inst) + (index)))
#define QNCAST(type, var, inst) type *var = (type *)(inst)

struct setp_node_t {
    hash_area_t *setp_ha;
    struct {
        state_slot_t *ssa_set_no;
    } setp_ssa;
    int setp_set_no_in_key;
};

struct hash_area_t {
    int ha_n_keys;
    state_slot_t **ha_slots;
    index_tree_t *ha_tree;
};

struct index_tree_t {
    hash_item_t *it_hi;
};

struct hash_item_t {
    chash_t *hi_chash;
};

struct chash_t {
    int cha_oversized;
    int cha_n_keys;
    mem_pool_t *cha_pool;
    sqt_t *cha_sqt;
};

struct data_col_t {
    int dc_n_values;
    int dc_dtp;
    int dc_type;
};

struct state_slot_t {
    int ssl_type;
    int ssl_index;
};

struct mem_pool_t {
    size_t mp_bytes;
};

struct sqt_t {
    int sqt_dtp;
};

extern int enable_chash_distinct;
extern int cluster_enable;
extern size_t cha_max_gb_bytes;
extern size_t mp_large_in_use;
extern size_t c_max_large_vec;
extern int SSL_CONSTANT;
extern int SSL_VEC;
extern int DCT_BOXES;
extern int DV_ANY;
extern int CHASH_GB_MAX_KEYS;

index_tree_t *qst_tree(caddr_t *inst, index_tree_t *tree, state_slot_t *slot);
index_tree_t *cha_allocate(setp_node_t *setp, caddr_t *inst, int flag);
void setp_chash_distinct_run(setp_node_t *setp, caddr_t *inst, index_tree_t *tree);
void chash_to_memcache(caddr_t *inst, index_tree_t *tree, hash_area_t *ha);