#include <sys/types.h>
#include <stddef.h>

struct device;
struct device_attribute;
struct mutex;

extern unsigned long check_interval;
extern struct mutex mce_sysfs_mutex;
extern void mce_restart(void);
extern ssize_t device_store_ulong(struct device *, struct device_attribute *, const char *, size_t);