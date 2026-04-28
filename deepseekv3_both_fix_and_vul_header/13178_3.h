#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

struct rds_zcopy_cookies {
    u32 num;
    u32 cookies[0];
};

struct rds_msg_zcopy_queue {
    int lock;
    struct list_head zcookie_head;
};

struct rds_msg_zcopy_info {
    struct rds_zcopy_cookies zcookies;
    struct list_head rs_zcookie_next;
};

struct rds_sock {
    struct rds_msg_zcopy_queue rs_zcookie_queue;
};

struct rds_znotifier {
    u32 z_cookie;
    void *z_mmp;
};

#define list_empty(head) ((head)->next == (head))
#define list_first_entry(head, type, member) \
    ((type *)((char *)((head)->next) - offsetof(type, member)))
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
#define list_add_tail(new, head) do { \
    (new)->next = (head); \
    (new)->prev = (head)->prev; \
    (head)->prev->next = (new); \
    (head)->prev = (new); \
} while (0)

static inline struct rds_msg_zcopy_info *rds_info_from_znotifier(struct rds_znotifier *znotif)
{
    return (struct rds_msg_zcopy_info *)((char *)znotif - offsetof(struct rds_msg_zcopy_info, zcookies));
}

static inline int rds_zcookie_add(struct rds_msg_zcopy_info *info, u32 cookie)
{
    return 0;
}

static inline void spin_lock_irqsave(int *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) { (void)lock; (void)flags; }
static inline void mm_unaccount_pinned_pages(void *mmp) { (void)mmp; }
static inline void WARN_ON(int condition) { (void)condition; }
static inline void kfree(void *ptr) { free(ptr); }