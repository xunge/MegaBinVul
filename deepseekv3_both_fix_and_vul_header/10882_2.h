#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <errno.h>

typedef unsigned long long u64;

struct device;
struct device_attribute;
struct mutex;

struct mca_config {
    bool ignore_ce;
};
extern struct mca_config mca_cfg;
extern struct mutex mce_sysfs_mutex;

int kstrtou64(const char *s, unsigned int base, u64 *res);
void mce_timer_delete_all(void);
void mce_disable_cmci(void *info);
void mce_enable_ce(void *arg);
void on_each_cpu(void (*func)(void *info), void *info, int wait);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);