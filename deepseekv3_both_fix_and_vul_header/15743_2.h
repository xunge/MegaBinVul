#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>

#define SMC_LINKS_PER_LGR_MAX 2
#define SMC_LLC_DEL_OP_INIT_TERM 0

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

struct smc_ib_device {
    atomic_int lnk_cnt;
    int lnks_deleted;
};

struct smc_link {
    struct smc_ib_device *smcibdev;
};

struct smc_link_group {
    struct list_head list;
    int freeing;
    struct smc_link lnk[SMC_LINKS_PER_LGR_MAX];
    int llc_conf_mutex;
};

struct smc_lgr_list {
    struct list_head list;
    int lock;
};

extern struct smc_lgr_list smc_lgr_list;
extern atomic_int lgr_cnt;
extern int lgrs_deleted;

void smc_llc_set_termination_rsn(struct smc_link_group *lgr, int reason);
void __smc_lgr_terminate(struct smc_link_group *lgr, bool soft);
void smcr_link_down_cond(struct smc_link *lnk);

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define list_splice_init(list, head) do { \
    (head)->next = (list)->next; \
    (head)->prev = (list)->prev; \
    (list)->next = (list); \
    (list)->prev = (list); \
} while (0)

#define list_move_tail(list, head) do { \
    (list)->prev->next = (list)->next; \
    (list)->next->prev = (list)->prev; \
    (list)->next = (head); \
    (list)->prev = (head)->prev; \
    (head)->prev->next = (list); \
    (head)->prev = (list); \
} while (0)

#define list_del_init(list) do { \
    (list)->prev->next = (list)->next; \
    (list)->next->prev = (list)->prev; \
    (list)->next = (list); \
    (list)->prev = (list); \
} while (0)

#define spin_lock_bh(lock) (void)0
#define spin_unlock_bh(lock) (void)0
#define mutex_lock(lock) (void)0
#define mutex_unlock(lock) (void)0
#define wait_event(wq, condition) (void)0