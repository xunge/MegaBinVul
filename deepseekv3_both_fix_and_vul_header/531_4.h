#include <stddef.h>
#include <errno.h>
#include <stdint.h>

#define RT6_TABLE_DFLT 0
#define MRT6_VERSION 0x0305
#define MRT6_PIM 0x0306
#define MRT6_ASSERT 0x0307
#define IPPROTO_ICMPV6 58
#define SOCK_RAW 3
#define EOPNOTSUPP 95
#define ENOENT 2
#define ENOPROTOOPT 92
#define EFAULT 14
#define EINVAL 22

typedef uint32_t u32;

struct sock {
    int sk_type;
};
struct net;
struct mr6_table {
    int mroute_do_pim;
    int mroute_do_assert;
};
struct inet_sock {
    int inet_num;
};
struct raw6_sock {
    int ip6mr_table;
};

#define __user
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline int get_user(int val, int __user *addr) { return 0; }
static inline int put_user(int val, int __user *addr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }

struct mr6_table *ip6mr_get_table(struct net *net, u32 id) { return NULL; }
struct net *sock_net(struct sock *sk) { return NULL; }
struct inet_sock *inet_sk(const struct sock *sk) { return NULL; }
struct raw6_sock *raw6_sk(const struct sock *sk) { return NULL; }