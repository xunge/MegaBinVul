#define __init

#include <linux/module.h>
#include <linux/net.h>
#include <linux/socket.h>
#include <linux/netdevice.h>

struct sk_buff;
struct net_device;
struct packet_type;
struct notifier_block;

extern struct proto ddp_proto;
extern struct net_proto_family atalk_family_ops;
extern unsigned char ddp_snap_id[];
extern const char atalk_err_snap[];
extern struct packet_type ltalk_packet_type;
extern struct packet_type ppptalk_packet_type;
extern struct notifier_block ddp_notifier;
extern void *ddp_dl;
extern void atalk_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev);
extern int aarp_proto_init(void);
extern int atalk_proc_init(void);
extern int atalk_register_sysctl(void);