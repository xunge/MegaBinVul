#include <string.h>
#include <stdint.h>

#define IFNAMSIZ 16
#define GFP_KERNEL 0
#define ENOBUFS 105
#define RTM_NEWNETCONF 0
#define NETCONFA_ALL 0

struct net_device {
    char name[IFNAMSIZ];
};

struct net;

struct mpls_dev {
    void *sysctl;
};

struct ctl_table {
    const char *procname;
    void *data;
    int maxlen;
    int mode;
    struct ctl_table *child;
    void *extra1;
    void *extra2;
};

static struct ctl_table mpls_dev_table[] = {
    {0}
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

extern struct net *dev_net(struct net_device *dev);
extern void *kmemdup(const void *src, size_t len, int gfp);
extern void kfree(const void *obj);
extern int snprintf(char *str, size_t size, const char *format, ...);
extern void *register_net_sysctl(struct net *net, const char *path, struct ctl_table *table);
extern int mpls_netconf_notify_devconf(struct net *net, int event, int type, struct mpls_dev *mdev);