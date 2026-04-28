#include <stddef.h>
#include <sys/types.h>

struct proto {
    /* dummy structure */
};

struct net_proto_family {
    /* dummy structure */  
};

struct datalink_proto {
    /* dummy structure */
};

struct packet_type {
    /* dummy structure */
};

struct notifier_block {
    /* dummy structure */
};

struct sk_buff {
    /* dummy structure */
};

struct net_device {
    /* dummy structure */
};

#define __init
#define PF_APPLETALK 5
#define pr_crit(fmt, ...) printk(fmt, ##__VA_ARGS__)

extern struct proto ddp_proto;
extern struct net_proto_family atalk_family_ops;
extern unsigned char ddp_snap_id[];
extern struct datalink_proto *ddp_dl;
extern struct packet_type ltalk_packet_type;
extern struct packet_type ppptalk_packet_type;
extern struct notifier_block ddp_notifier;
extern void atalk_rcv(struct sk_buff *, struct net_device *,
                     struct packet_type *, struct net_device *);
extern const char atalk_err_snap[];

int proto_register(struct proto *, int);
int sock_register(struct net_proto_family *);
struct datalink_proto *register_snap_client(unsigned char *, void (*)(struct sk_buff *, struct net_device *,
                                    struct packet_type *, struct net_device *));
int printk(const char *fmt, ...);
int dev_add_pack(struct packet_type *);
int register_netdevice_notifier(struct notifier_block *);
int aarp_proto_init(void);
int atalk_proc_init(void);
int atalk_register_sysctl(void);
void atalk_proc_exit(void);
void aarp_cleanup_module(void);
int unregister_netdevice_notifier(struct notifier_block *);
void dev_remove_pack(struct packet_type *);
void unregister_snap_client(struct datalink_proto *);
int sock_unregister(int);
void proto_unregister(struct proto *);