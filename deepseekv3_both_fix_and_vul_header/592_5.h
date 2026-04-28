#include <stddef.h>
#include <sys/types.h>

struct net;
struct ctl_table_header;

struct ctl_table {
    const char *procname;
    void *data;
    int maxlen;
    int mode;
    struct ctl_table *child;
    int (*proc_handler)(struct ctl_table *, int, void *, size_t *, loff_t *);
};

#define __init
#define ENOMEM 12

extern struct net init_net;
extern struct ctl_table_header *atalk_table_header;
extern struct ctl_table atalk_table[];
extern struct ctl_table_header *register_net_sysctl(struct net *, const char *, struct ctl_table *);