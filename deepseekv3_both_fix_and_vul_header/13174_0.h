#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

struct file;
struct inode {
    dev_t i_rdev;
    uid_t i_uid;
};
struct net;
struct nsproxy {
    struct net *net_ns;
};
struct task_struct {
    struct nsproxy *nsproxy;
};
extern struct task_struct *current;

struct tap_dev {
    struct {
        unsigned int tx_queue_len;
        unsigned int features;
    } *dev;
};
struct tap_queue {
    void *ring;
    struct {
        struct {
            struct {
                void *wait;
            } wq;
            int type;
            int state;
            struct file *file;
            void *ops;
        } sock;
        struct {
            void (*sk_write_space)(struct tap_queue *);
            void (*sk_destruct)(struct tap_queue *);
        } sk;
    };
    unsigned int flags;
    unsigned int vnet_hdr_sz;
};
struct tap_proto {
    int dummy;
};
struct tap_socket_ops {
    int dummy;
};
struct virtio_net_hdr {
    unsigned char flags;
    unsigned char gso_type;
    unsigned short hdr_len;
    unsigned short gso_size;
    unsigned short csum_start;
    unsigned short csum_offset;
};

static struct tap_proto tap_proto;
static struct tap_socket_ops tap_socket_ops;

#define ENODEV 19
#define ENOMEM 12
#define GFP_KERNEL 0
#define AF_UNSPEC 0
#define SOCK_RAW 3
#define SS_CONNECTED 1
#define IFF_VNET_HDR 0x1000
#define IFF_NO_PI 0x1000
#define IFF_TAP 0x0002
#define NETIF_F_HIGHDMA 0x00002000
#define NETIF_F_SG 0x00000002
#define SOCK_ZEROCOPY 0x00000001

static void tap_sock_write_space(struct tap_queue *q) {}
static void tap_sock_destruct(struct tap_queue *q) {}
static int tap_set_queue(struct tap_dev *tap, struct file *file, struct tap_queue *q) { return 0; }
static void rtnl_lock(void) {}
static void rtnl_unlock(void) {}
static void sock_init_data(void *sock, void *sk) {}
static void sock_set_flag(void *sk, int flag) {}
static void sock_put(void *sk) {}
static void sk_free(void *sk) {}
static int ptr_ring_init(void *ring, int len, int flags) { return 0; }
static void dev_put(void *dev) {}
static struct tap_dev *dev_get_by_tap_file(int major, int minor) { return NULL; }
static void *sk_alloc(struct net *net, int family, int flags, void *proto, int kern) { return NULL; }
static void init_waitqueue_head(void *wq) {}
static unsigned int imajor(struct inode *inode) { return 0; }
static unsigned int iminor(struct inode *inode) { return 0; }