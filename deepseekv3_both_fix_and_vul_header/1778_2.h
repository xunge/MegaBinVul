#include <errno.h>
#include <stdbool.h>

struct damon_sysfs_target {
    int pid;
    void *regions;
};

struct damon_target {
    void *pid;
};

struct damon_ctx;

extern struct damon_target *damon_new_target(void);
extern bool damon_target_has_pid(struct damon_ctx *ctx);
extern void damon_add_target(struct damon_ctx *ctx, struct damon_target *t);
extern int damon_sysfs_set_regions(struct damon_target *t, void *regions);
extern void damon_sysfs_destroy_targets(struct damon_ctx *ctx);
extern void *find_get_pid(int pid);