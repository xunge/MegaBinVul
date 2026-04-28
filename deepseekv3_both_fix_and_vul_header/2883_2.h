#include <stddef.h>
#include <string.h>

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct net;

struct ifconf {
    int ifc_len;
    union {
        void *ifcu_buf;
        struct ifreq *ifcu_req;
    } ifc_ifcu;
};
#define ifc_buf ifc_ifcu.ifcu_buf
#define ifc_req ifc_ifcu.ifcu_req

struct ifreq {
    union {
        char ifrn_name[16];
    } ifr_ifrn;
    union {
        struct sockaddr ifru_addr;
        struct sockaddr ifru_dstaddr;
        struct sockaddr ifru_broadaddr;
        struct sockaddr ifru_netmask;
        struct sockaddr ifru_hwaddr;
        short ifru_flags;
        int ifru_ivalue;
        int ifru_mtu;
        void *ifru_data;
    } ifr_ifru;
};

struct compat_ifconf {
    int ifc_len;
    void *ifcbuf;
};

struct compat_ifreq {
    char ifrn_name[16];
    union {
        struct sockaddr ifru_addr;
        struct sockaddr ifru_dstaddr;
        struct sockaddr ifru_broadaddr;
        struct sockaddr ifru_netmask;
        struct sockaddr ifru_hwaddr;
        short ifru_flags;
        int ifru_ivalue;
        int ifru_mtu;
        void *ifru_data;
    } ifr_ifru;
};

#define __user
#define SIOCGIFCONF 0x8912
#define IFNAMSIZ 16
#define EFAULT 14

static void *compat_alloc_user_space(size_t len) { return NULL; }
static void *compat_ptr(void *uptr) { return uptr; }
static int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static int copy_in_user(void __user *to, const void __user *from, unsigned long n) { return 0; }
static int dev_ioctl(struct net *net, int cmd, void *arg) { return 0; }