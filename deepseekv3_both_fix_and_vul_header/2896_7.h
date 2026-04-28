#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <stdint.h>

#define IFF_TUN           0x0001
#define IFF_TAP           0x0002
#define IFF_NO_PI         0x1000
#define IFF_ONE_QUEUE     0x2000
#define IFF_VNET_HDR      0x4000

#define TUN_TYPE_MASK     0x000f
#define TUN_TAP_DEV       0x0001
#define TUN_PERSIST       0x0200

#define TUNSETIFF         _IOW('T', 202, int)
#define TUNGETFEATURES    _IOR('T', 207, unsigned int)
#define TUNGETIFF         _IOR('T', 210, unsigned int)
#define TUNSETNOCSUM      _IOW('T', 200, int)
#define TUNSETPERSIST     _IOW('T', 201, int)
#define TUNSETOWNER       _IOW('T', 203, int)
#define TUNSETGROUP       _IOW('T', 204, int)
#define TUNSETLINK        _IOW('T', 205, int)
#define TUNSETOFFLOAD     _IOW('T', 208, unsigned int)
#define TUNSETTXFILTER    _IOW('T', 209, unsigned int)
#define TUNGETSNDBUF      _IOR('T', 211, int)
#define TUNSETSNDBUF      _IOW('T', 212, int)
#define TUNGETVNETHDRSZ   _IOR('T', 215, int)
#define TUNSETVNETHDRSZ   _IOW('T', 216, int)
#define TUNATTACHFILTER   _IOW('T', 213, struct sock_fprog)
#define TUNDETACHFILTER   _IOR('T', 214, int)

#define SIOCGIFHWADDR     0x8927
#define SIOCSIFHWADDR     0x8924

#define ETH_ALEN          6
#define IFNAMSIZ          IF_NAMESIZE

#define KERN_INFO         0
#define KERN_DEBUG        1

struct sock_fprog {
    uint16_t len;
    void *filter;
};

struct virtio_net_hdr {
    uint8_t flags;
    uint8_t gso_type;
    uint16_t hdr_len;
    uint16_t gso_size;
    uint16_t csum_start;
    uint16_t csum_offset;
};

struct file {
    void *private_data;
};

struct tun_file {
    void *net;
};

struct tun_struct {
    unsigned int flags;
    uid_t owner;
    gid_t group;
    struct {
        struct {
            int sk_sndbuf;
        } *sk;
    } socket;
    struct {
        unsigned short type;
        unsigned int flags;
        unsigned char dev_addr[ETH_ALEN];
    } *dev;
    int vnet_hdr_sz;
    void *txflt;
};

struct current_struct {
    struct {
        void *net_ns;
    } *nsproxy;
};

extern struct current_struct *current;

static inline void *user_ptr(unsigned long addr) {
    return (void *)addr;
}

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline int put_user(unsigned int val, void *addr) {
    *(unsigned int *)addr = val;
    return 0;
}

static inline void rtnl_lock(void) {}
static inline void rtnl_unlock(void) {}
static inline int __tun_get(struct tun_file *tfile) { return 0; }
static inline int tun_set_iff(void *net, struct file *file, struct ifreq *ifr) { return 0; }
static inline void tun_debug(int level, struct tun_struct *tun, const char *fmt, ...) {}
static inline int tun_get_iff(void *net_ns, struct tun_struct *tun, struct ifreq *ifr) { return 0; }
static inline int set_offload(struct tun_struct *tun, unsigned long arg) { return 0; }
static inline int update_filter(void *txflt, void *arg) { return 0; }
static inline int dev_set_mac_address(void *dev, void *addr) { return 0; }
static inline int sk_attach_filter(struct sock_fprog *fprog, void *sk) { return 0; }
static inline int sk_detach_filter(void *sk) { return 0; }
static inline void tun_put(struct tun_struct *tun) {}

#define __user