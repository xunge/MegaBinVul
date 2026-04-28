#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

struct net;
struct net_device;

#define CAP_NET_ADMIN 0
#define CAP_SYS_MODULE 0

void rcu_read_lock(void);
void rcu_read_unlock(void);
struct net_device *dev_get_by_name_rcu(struct net *net, const char *name);
int capable(int cap);
int request_module(const char *fmt, ...);
void pr_err(const char *fmt, ...);