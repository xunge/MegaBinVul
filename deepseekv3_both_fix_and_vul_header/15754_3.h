#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

typedef long ssize_t;
typedef long loff_t;

struct damon_ctx {
    int kdamond_lock;
    void *kdamond;
    struct damon_target *targets;
};

struct damon_target {
    unsigned long id;
    struct damon_target *next;
};

struct file {
    void *private_data;
};

struct pid {
    int dummy;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define ENOMEM 12
#define EINVAL 22
#define EBUSY 16

static char *user_input_str(const char *buf, size_t count, loff_t *ppos);
static unsigned long *str_to_target_ids(char *nrs, size_t count, ssize_t *nr_targets);
static void dbgfs_put_pids(unsigned long *targets, int nr_targets);
static bool targetid_is_pid(struct damon_ctx *ctx);
static void put_pid(struct pid *pid);
static void damon_destroy_target(struct damon_target *t);
static void damon_va_set_primitives(struct damon_ctx *ctx);
static void damon_pa_set_primitives(struct damon_ctx *ctx);
static int damon_set_targets(struct damon_ctx *ctx, unsigned long *targets, ssize_t nr_targets);
static struct pid *find_get_pid(int nr);

static inline void mutex_lock(int *lock) { (void)lock; }
static inline void mutex_unlock(int *lock) { (void)lock; }
static inline void kfree(void *ptr) { free(ptr); }

#define damon_for_each_target_safe(t, next_t, ctx) \
    for (t = (ctx)->targets, next_t = t ? t->next : NULL; t; \
            t = next_t, next_t = t ? t->next : NULL)

#define __user