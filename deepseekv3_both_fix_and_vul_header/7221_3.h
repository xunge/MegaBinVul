#include <stddef.h>

#define PJ_DEF(ret) ret
typedef int pj_status_t;
#define PJ_EINVAL 1
#define PJ_EINVALIDOP 2
#define PJ_SUCCESS 0

#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)
#define pj_assert(expr) ((void)0)

struct pj_str_t {
    char *ptr;
    unsigned slen;
};

struct pj_list {
    struct pj_list *next;
    struct pj_list *prev;
};

struct pj_hash_table_t;
struct pj_hash_entry;
struct pj_mutex_t;

struct dlg_set {
    struct pj_list dlg_list;
    struct pj_str_t ht_key;
    struct pj_hash_entry *ht_entry;
};

struct mod_ua {
    struct pj_mutex_t *mutex;
    struct pj_hash_table_t *dlg_table;
    struct pj_list free_dlgset_nodes;
};

extern struct mod_ua mod_ua;

struct pjsip_dialog {
    struct dlg_set *dlg_set;
    struct pjsip_dialog *next;
    struct {
        unsigned tag_hval;
        struct {
            struct pj_str_t tag;
        } *info;
    } local;
};

typedef struct pjsip_user_agent pjsip_user_agent;
typedef struct pjsip_dialog pjsip_dialog;

void pj_mutex_lock(struct pj_mutex_t*);
void pj_mutex_unlock(struct pj_mutex_t*);
void pj_list_erase(void*);
int pj_list_empty(struct pj_list*);
void pj_list_push_back(struct pj_list*, void*);
void* pj_hash_get_lower(struct pj_hash_table_t*, const char*, unsigned, unsigned*);
void pj_hash_set_lower(void*, struct pj_hash_table_t*, const char*, unsigned, unsigned, void*);
void pj_hash_set_np_lower(struct pj_hash_table_t*, const char*, unsigned, unsigned, struct pj_hash_entry*, void*);