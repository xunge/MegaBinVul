#include <stdbool.h>
#include <sys/types.h>
#include <stddef.h>
#include <errno.h>

typedef unsigned long long u64;

struct device;
struct device_attribute;

extern struct mutex mce_sysfs_mutex;
extern struct mca_config {
    bool cmci_disabled;
} mca_cfg;

extern int kstrtou64(const char *s, unsigned int base, u64 *res);
extern void on_each_cpu(void (*func)(void *info), void *info, int wait);
extern void mce_disable_cmci(void *info);
extern void mce_enable_ce(void *info);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);