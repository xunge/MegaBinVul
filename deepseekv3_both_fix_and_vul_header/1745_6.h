#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct list_head {
    struct list_head *next, *prev;
};

struct cfg80211_bss_ies {
    struct list_head rcu_head;
};

struct cfg80211_bss {
    void *channel;
    void *ies;
    void *beacon_ies;
    void *proberesp_ies;
    void *hidden_beacon_bss;
    void *transmitted_bss;
    struct list_head nontrans_list;
};

struct cfg80211_internal_bss {
    struct cfg80211_bss pub;
    unsigned long ts;
    struct list_head list;
    struct list_head hidden_list;
    int refcount;
};

struct wiphy {
    size_t bss_priv_size;
};

struct cfg80211_registered_device {
    struct wiphy wiphy;
    int bss_lock;
    struct list_head bss_list;
    unsigned int bss_entries;
    unsigned int bss_generation;
};

#define WARN_ON(condition) (condition)
#define GFP_ATOMIC 0
#define BSS_CMP_REGULAR 0
#define BSS_CMP_HIDE_ZLEN 1
#define BSS_CMP_HIDE_NUL 2
#define bss_entries_limit 100

static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}
static inline void *rcu_access_pointer(void *p) { return p; }
static inline void *rcu_dereference(void *p) { return p; }
static inline void rcu_assign_pointer(void *p, void *v) { }
static inline void kfree_rcu(struct cfg80211_bss_ies *ies, struct list_head *head) { }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}
static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

static inline void bss_ref_put(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *bss) {}
static inline void bss_ref_get(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *bss) {}
static inline bool cfg80211_update_known_bss(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *found, struct cfg80211_internal_bss *tmp, bool signal_valid) { return false; }
static inline bool cfg80211_combine_bsses(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *new) { return false; }
static inline bool cfg80211_bss_expire_oldest(struct cfg80211_registered_device *rdev) { return false; }
static inline struct cfg80211_internal_bss *rb_find_bss(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *tmp, int cmp_type) { return NULL; }
static inline void rb_insert_bss(struct cfg80211_registered_device *rdev, struct cfg80211_internal_bss *new) {}

static struct list_head *rcu_head = NULL;