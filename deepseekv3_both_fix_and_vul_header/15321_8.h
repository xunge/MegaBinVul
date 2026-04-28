#include <linux/module.h>
#include <linux/netlink.h>
#include <linux/connector.h>
#include <linux/types.h>
#include <stddef.h>

#define __devinit
#define S_IRUGO 0444
#define THIS_MODULE NULL
#define EIO 5
#define EINVAL 22

static struct cn_dev cdev;
static int cn_idx;
static int cn_val;
static int cn_already_initialized;

struct cn_dev {
    void (*input)(void *skb);
    struct cb_id id;
    void *nls;
    void *cbdev;
};

struct file_operations {
    int dummy;
};

static struct file_operations cn_file_ops;

struct net {
    int dummy;
};

extern struct net init_net;

static void cn_rx_skb(void *skb) {}
static void *cn_queue_alloc_dev(const char *name, void *nls) { return NULL; }
static void cn_queue_free_dev(void *dev) {}
static int cn_add_callback(const struct cb_id *id, const char *name,
                         void (*callback)(void *, void *)) { return 0; }
static void cn_callback(void *msg, void *nsp) {}
static int proc_net_fops_create(struct net *net, const char *name, unsigned int mode,
                              const struct file_operations *fops) { return 0; }
static void *netlink_kernel_create(struct net *net, int unit, unsigned int groups,
                                 void (*input)(void *skb), void *data, void *module) { return NULL; }
static void netlink_kernel_release(void *sk) {}