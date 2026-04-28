#include <stddef.h>

#define PJ_DEF(ret_type) ret_type

typedef int pj_status_t;
#define PJ_EINVAL 1
#define PJ_EBUG 2
#define PJ_SUCCESS 0

#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)
#define pj_assert(expr) ((void)0)

typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pj_hash_entry {
    struct pj_hash_entry *next;
    unsigned int hval;
    void *key;
    void *value;
} pj_hash_entry;

typedef struct pj_hash_table_t {
    unsigned int size;
    pj_hash_entry **table;
} pj_hash_table_t;

typedef struct pj_mutex_t {
    void *dummy;
} pj_mutex_t;

typedef struct pjsip_dialog_local {
    struct {
        pj_str_t tag;
    } *info;
    unsigned int tag_hval;
} pjsip_dialog_local;

typedef struct pjsip_dialog {
    pjsip_dialog_local local;
    int role;
    void *dlg_set;
} pjsip_dialog;

typedef struct pjsip_user_agent {
    void *dummy;
} pjsip_user_agent;

struct dlg_set {
    pj_str_t ht_key;
    struct {
        struct dlg_set *next;
        struct dlg_set *prev;
    } dlg_list;
    pj_hash_entry ht_entry[1];
};

struct {
    pj_mutex_t *mutex;
    pj_hash_table_t *dlg_table;
} mod_ua;

#define PJSIP_ROLE_UAC 0
#define PJSIP_ROLE_UAS 1

static void pj_list_init(void *list) {}
static void pj_list_push_back(void *list, void *item) {}
static void *pj_hash_get_lower(pj_hash_table_t *ht, const void *key, unsigned keylen, unsigned *hval) { return NULL; }
static void pj_hash_set_np_lower(pj_hash_table_t *ht, const void *key, unsigned keylen, unsigned hval, pj_hash_entry *entry, void *value) {}
static void pj_mutex_lock(pj_mutex_t *mutex) {}
static void pj_mutex_unlock(pj_mutex_t *mutex) {}
static struct dlg_set* alloc_dlgset_node(void) { return NULL; }