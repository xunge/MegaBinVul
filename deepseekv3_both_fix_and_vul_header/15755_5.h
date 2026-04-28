#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ENOMEM 12
#define EINVAL 22
#define EBUSY 16

struct file {
    void *private_data;
};

struct damon_ctx {
    void *kdamond;
    int kdamond_lock;
    struct damon_target *targets;
};

struct damon_target {
    unsigned long id;
    struct damon_target *next;
};

struct pid;

static char *user_input_str(const char *buf, size_t count, loff_t *ppos);
static unsigned long *str_to_target_ids(char *nrs, ssize_t ret, ssize_t *nr_targets);
static bool targetid_is_pid(struct damon_ctx *ctx);
static void dbgfs_put_pids(unsigned long *targets, int nr_targets);
static void damon_destroy_target(struct damon_target *t);
static int damon_set_targets(struct damon_ctx *ctx, unsigned long *targets, ssize_t nr_targets);
static struct pid *find_get_pid(int pid);
static void put_pid(struct pid *pid);
static void mutex_lock(int *lock);
static void mutex_unlock(int *lock);
static void kfree(void *ptr);

#define damon_for_each_target_safe(t, next_t, ctx) \
    for (t = (ctx)->targets, next_t = t ? t->next : NULL; \
         t; \
         t = next_t, next_t = t ? t->next : NULL)