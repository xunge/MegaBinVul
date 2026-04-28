#include <stddef.h>
#include <sys/types.h>

#define CHASH_GB_MAX_KEYS 32
#define SSL_CONSTANT 0
#define SSL_VEC 1
#define DCT_BOXES 1
#define DV_ANY 1

typedef struct state_slot state_slot_t;
typedef struct hash_area hash_area_t;
typedef struct chash chash_t;
typedef struct sqt sqt_t;
typedef struct mempool mempool_t;
typedef struct hash_index hash_index_t;

struct state_slot {
    int ssl_type;
    int ssl_index;
};

struct hash_area {
    int ha_n_keys;
    state_slot_t **ha_slots;
    void *ha_tree;
};

struct hash_index {
    chash_t *hi_chash;
};

struct chash {
    int cha_n_keys;
    int cha_oversized;
    mempool_t *cha_pool;
    sqt_t *cha_sqt;
};

struct sqt {
    int sqt_dtp;
};

struct mempool {
    size_t mp_bytes;
};

typedef struct {
    state_slot_t *ssa_set_no;
} setp_ssa_t;

typedef struct setp_node {
    hash_area_t *setp_ha;
    setp_ssa_t setp_ssa;
    int setp_set_no_in_key;
} setp_node_t;

typedef struct {
    int dc_n_values;
    int dc_dtp;
    int dc_type;
} data_col_t;

typedef struct {
    int qi_set;
} query_instance_t;

typedef struct {
    hash_index_t *it_hi;
} index_tree_t;

extern int enable_chash_distinct;
extern int cluster_enable;
extern size_t cha_max_gb_bytes;
extern size_t mp_large_in_use;
extern size_t c_max_large_vec;

#define BOX_ELEMENTS(arr) (sizeof(arr)/sizeof((arr)[0]))
#define QST_BOX(type, inst, idx) ((type)((char *)(inst) + (idx)))
#define QNCAST(type, var, ptr) type *var = (type *)(ptr)

index_tree_t *qst_tree(caddr_t *inst, void *tree, state_slot_t *set_no);
index_tree_t *cha_allocate(setp_node_t *setp, caddr_t *inst, int flag);
void setp_chash_distinct_run(setp_node_t *setp, caddr_t *inst, index_tree_t *tree);
void chash_to_memcache(caddr_t *inst, index_tree_t *tree, hash_area_t *ha);