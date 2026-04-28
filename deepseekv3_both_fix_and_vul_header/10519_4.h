#include <string.h>
#include <sys/ioctl.h>

#define AF_IPX 4
#define IPX_NODE_LEN 6
#define EINVAL 22
#define EFAULT 14
#define ENODEV 19
#define EADDRNOTAVAIL 99

#define SIOCSIFADDR 0x8916
#define SIOCGIFADDR 0x8915
#define SIOCAIPXITFCRT 0x8937
#define SIOCAIPXPRISLT 0x8938
#define IPX_DLTITF 0x00

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_ipx {
    unsigned short sipx_family;
    unsigned short sipx_port;
    unsigned int sipx_network;
    unsigned char sipx_node[IPX_NODE_LEN];
    unsigned char sipx_type;
    unsigned char sipx_special;
    unsigned char sipx_action;
};

struct ipx_interface_definition {
    unsigned int ipx_network;
    char ipx_device[16];
    unsigned char ipx_node[IPX_NODE_LEN];
    unsigned char ipx_dlink_type;
    unsigned char ipx_special;
};

struct ipx_interface {
    unsigned int if_netnum;
    unsigned char if_node[IPX_NODE_LEN];
};

struct net_device;
struct net;

struct ifreq {
    char ifr_name[16];
    union {
        struct sockaddr ifr_addr;
        struct sockaddr_ipx ifr_ipx_addr;
    };
};

extern struct net init_net;

extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern int get_user(int *val, const void *from);

extern int ipxitf_delete(struct ipx_interface_definition *f);
extern int ipxitf_create(struct ipx_interface_definition *f);
extern struct ipx_interface *ipxitf_find_using_phys(struct net_device *dev, unsigned short frame_type);
extern void ipxitf_put(struct ipx_interface *ipxif);
extern unsigned short ipx_map_frame_type(unsigned char type);
extern void ipxcfg_set_auto_select(int val);
extern struct net_device *__dev_get_by_name(struct net *net, const char *name);

extern int ipxcfg_auto_create_interfaces;

#define __user