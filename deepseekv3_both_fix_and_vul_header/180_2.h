#include <string.h>
#include <errno.h>

#define IFNAMSIZ 16
#define BUG_ON(condition) ((void)0)
#define EINVAL 22
#define EEXIST 17

struct net;

struct net_device {
    char name[IFNAMSIZ];
};

int dev_valid_name(const char *name);
int dev_alloc_name_ns(struct net *net, struct net_device *dev, const char *name);
struct net_device *__dev_get_by_name(struct net *net, const char *name);
size_t strlcpy(char *dest, const char *src, size_t size);