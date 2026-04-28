#include <stdint.h>
#include <stdatomic.h>

typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct calipso_doi {
    struct list_head list;
    _Atomic int refcount;
    struct rcu_head rcu;
    u32 doi;
};

struct netlbl_audit;
struct audit_buffer;

extern void spin_lock(_Atomic int *lock);
extern void spin_unlock(_Atomic int *lock);
extern _Atomic int calipso_doi_list_lock;
extern struct calipso_doi *calipso_doi_search(u32 doi);
extern void calipso_doi_free_rcu(struct rcu_head *head);
extern void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head));
extern void list_del_rcu(struct list_head *entry);
extern struct audit_buffer *netlbl_audit_start(int type, struct netlbl_audit *audit_info);
extern void audit_log_format(struct audit_buffer *ab, const char *fmt, ...);
extern void audit_log_end(struct audit_buffer *ab);

#define ENOENT 2
#define EBUSY 16
#define AUDIT_MAC_CALIPSO_DEL 0