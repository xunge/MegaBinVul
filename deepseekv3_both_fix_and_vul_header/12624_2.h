#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
#define ENOENT 2
#define EBUSY 16
#define AUDIT_MAC_CIPSOV4_DEL 0

struct list_head {
    struct list_head *next, *prev;
};
struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};
typedef struct {
    int counter;
} refcount_t;

typedef struct {
    int lock;
} spinlock_t;

struct netlbl_audit;
struct audit_buffer;
struct cipso_v4_doi {
    struct list_head list;
    refcount_t refcount;
    struct rcu_head rcu;
    u32 doi;
};

extern spinlock_t cipso_v4_doi_list_lock;
extern struct cipso_v4_doi *cipso_v4_doi_search(u32 doi);
extern void cipso_v4_cache_invalidate(void);
extern void cipso_v4_doi_free_rcu(struct rcu_head *head);
extern struct audit_buffer *netlbl_audit_start(int type, struct netlbl_audit *audit_info);
extern void audit_log_format(struct audit_buffer *ab, const char *fmt, ...);
extern void audit_log_end(struct audit_buffer *ab);

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline int refcount_dec_and_test(refcount_t *r) { return 1; }
static inline void list_del_rcu(struct list_head *entry) { (void)entry; }
static inline void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head)) { (void)head; (void)func; }