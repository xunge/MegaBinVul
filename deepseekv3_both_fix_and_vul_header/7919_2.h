#include <stdbool.h>
#include <errno.h>

struct request_queue {
    void *queue_lock;
    struct blkcg_gq *root_blkg;
    struct {
        struct blkcg_gq *blkg;
    } root_rl;
};

struct blkcg_gq;
struct blkcg;

#define GFP_KERNEL 0
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))

extern struct blkcg blkcg_root;
extern struct blkcg_gq *blkg_alloc(struct blkcg *blkcg, struct request_queue *q, int gfp);
extern struct blkcg_gq *blkg_create(struct blkcg *blkcg, struct request_queue *q, struct blkcg_gq *new_blkg);
extern void blkg_free(struct blkcg_gq *blkg);
extern void blkg_destroy_all(struct request_queue *q);
extern int blk_throtl_init(struct request_queue *q);
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);
extern void spin_lock_irq(void *lock);
extern void spin_unlock_irq(void *lock);
extern int radix_tree_preload(int gfp);
extern void radix_tree_preload_end(void);