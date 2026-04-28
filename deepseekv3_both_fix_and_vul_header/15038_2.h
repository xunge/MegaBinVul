#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/io.h>

typedef uint32_t u32;
typedef uint8_t u8;

struct sbni_flags {
    u32 mac_addr;
    u8 rate;
    u8 slow_mode;
    u8 rxl;
    u8 fixed_rxl;
};

struct sbni_in_stats {
    /* define your stats fields here */
};

struct net_local {
    struct sbni_in_stats in_stats;
    int lock;
    struct {
        u8 rate;
        u8 rxl;
    } csr1;
    u32 state;
    u8 cur_rxl_index;
    u8 delta_rxl;
};

#define FL_SLOW_MODE 0x01
#define DEF_RXL_DELTA 1
#define DEF_RXL 2
#define PR_RES 0x80
#define CSR1 0

extern u8 rxl_tab[];

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EFAULT 2
#define EOPNOTSUPP 3
#define IFF_UP 0x1
#define KERN_ERR ""
#define SIOCDEVGETINSTATS 0
#define SIOCDEVRESINSTATS 1
#define SIOCDEVGHWSTATE 2
#define SIOCDEVSHWSTATE 3
#define SIOCDEVENSLAVE 4
#define SIOCDEVEMANSIPATE 5

struct ifreq {
    void *ifr_data;
    union {
        struct sbni_flags ifru;
    } ifr_ifru;
};

struct net_device {
    void *priv;
    u8 dev_addr[6];
    unsigned long base_addr;
    char *name;
    unsigned int flags;
};

struct task_struct {
    int euid;
};

extern struct task_struct *current;
extern struct net_device *dev_get_by_name(void *net, const char *name);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int enslave(struct net_device *dev, struct net_device *slave_dev);
extern int emancipate(struct net_device *dev);
extern void printk(const char *fmt, ...);
extern void spin_lock(int *lock);
extern void spin_unlock(int *lock);
extern int capable(int cap);