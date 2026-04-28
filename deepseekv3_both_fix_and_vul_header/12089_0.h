#include <stdlib.h>
#include <linux/types.h>

struct kobject;
typedef unsigned int gfp_t;

char *kzalloc(size_t size, gfp_t flags);
void kfree(const void *objp);
int get_kobj_path_length(const struct kobject *kobj);
int fill_kobj_path(const struct kobject *kobj, char *path, int len);