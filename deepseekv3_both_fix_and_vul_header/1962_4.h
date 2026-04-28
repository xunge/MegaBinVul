#include <stdio.h>
#include <netinet/in.h>

#define KERN_INFO ""
#define __exit
#define IPPROTO_GRE 47

extern struct rtnl_link_ops ipgre_tap_ops;
extern struct rtnl_link_ops ipgre_link_ops;
extern struct pernet_operations ipgre_net_ops;
extern struct net_protocol ipgre_protocol;

int rtnl_link_unregister(struct rtnl_link_ops *ops);
int unregister_pernet_device(struct pernet_operations *ops);
int inet_del_protocol(struct net_protocol *prot, unsigned char protocol);
int printk(const char *fmt, ...);