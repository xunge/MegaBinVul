#include <linux/netdevice.h>
#include <linux/rtnetlink.h>
#include <stdbool.h>

struct netdevsim;
struct net_device;
struct nsim_dev_port;

struct netdevsim {
    struct net_device *netdev;
    struct nsim_dev_port *nsim_dev_port;
    void *phc;
};

bool nsim_dev_port_is_pf(struct nsim_dev_port *nsim_dev_port);
void nsim_macsec_teardown(struct netdevsim *ns);
void nsim_ipsec_teardown(struct netdevsim *ns);
void nsim_bpf_uninit(struct netdevsim *ns);
void nsim_udp_tunnels_info_destroy(struct net_device *dev);
void mock_phc_destroy(void *phc);