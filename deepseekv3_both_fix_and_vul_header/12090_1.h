#include <string.h>

#define EINVAL 22
#define pr_debug(fmt, ...)

struct kobject {
    const char *name;
    struct kobject *parent;
};

static inline const char *kobject_name(const struct kobject *k) { return k->name; }