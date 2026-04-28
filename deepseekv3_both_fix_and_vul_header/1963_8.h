#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/net.h>
#include <linux/rtnetlink.h>
#include <linux/errno.h>
#include <linux/kernel.h>

#define __init
#define KERN_INFO ""

struct net_protocol;
struct pernet_operations;
struct rtnl_link_ops;

extern struct net_protocol ipgre_protocol;
extern struct pernet_operations ipgre_net_ops;
extern struct rtnl_link_ops ipgre_link_ops;
extern struct rtnl_link_ops ipgre_tap_ops;

extern int printk(const char *fmt, ...);
extern int inet_add_protocol(struct net_protocol *prot, unsigned char protocol);
extern int inet_del_protocol(struct net_protocol *prot, unsigned char protocol);
extern int register_pernet_device(struct pernet_operations *ops);
extern int unregister_pernet_device(struct pernet_operations *ops);
extern int rtnl_link_register(struct rtnl_link_ops *ops);
extern void rtnl_link_unregister(struct rtnl_link_ops *ops);