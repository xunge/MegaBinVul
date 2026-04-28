#include <stddef.h>
#include <string.h>

typedef struct {
    int max_slaves;
    int min_slaves;
} master_config_t;

typedef struct {
    int max_slaves;
    int min_slaves;
} equalizer_t;

struct net_device;
int eql_is_master(struct net_device *dev);
void *netdev_priv(const struct net_device *dev);

#define __user
#define EFAULT 14
#define EINVAL 22

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}