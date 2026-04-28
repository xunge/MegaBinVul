#define __init
#include <stdlib.h>
#include <string.h>

struct listeners {
    int dummy;  // 添加一个虚拟成员使结构体完整
};

struct netlink_table {
    int groups;
    struct listeners *listeners;
    void *module;
    int registered;
    int nl_nonroot;
};

extern struct netlink_table nl_table[];
#define NETLINK_USERSOCK 0
#define NLGRPSZ(g) (sizeof(void *) * (g))
#define GFP_KERNEL 0
#define NL_NONROOT_SEND 0
#define THIS_MODULE NULL

void *kzalloc(size_t size, int flags);
void netlink_table_grab(void);
void netlink_table_ungrab(void);
void rcu_assign_pointer(void *p1, void *p2);
void panic(const char *msg);