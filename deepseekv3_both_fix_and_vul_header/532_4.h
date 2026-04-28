#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stddef.h>

#define __user
#define ENOENT 2
#define EACCES 13
#define EOPNOTSUPP 95
#define EINVAL 22
#define ENFILE 23
#define EFAULT 14
#define ENOMEM 12
#define EBUSY 16
#define ENOPROTOOPT 92

#define CAP_NET_ADMIN 12
#define RT6_TABLE_DFLT 253
#define MAXMIFS 32
#define MRT6_INIT 200
#define MRT6_DONE 201
#define MRT6_ADD_MIF 202
#define MRT6_DEL_MIF 203
#define MRT6_ADD_MFC 204
#define MRT6_DEL_MFC 205
#define MRT6_ADD_MFC_PROXY 206
#define MRT6_DEL_MFC_PROXY 207
#define MRT6_ASSERT 208
#define MRT6_PIM 209
#define MRT6_TABLE 210

typedef unsigned int mifi_t;
typedef uint32_t u32;

struct mif6ctl {
    mifi_t mif6c_mifi;
    unsigned char mif6c_flags;
    unsigned char vifc_threshold;
    unsigned short mif6c_pifi;
    unsigned int vifc_rate_limit;
};

struct mf6cctl {
    struct sockaddr_in6 mf6cc_origin;
    struct sockaddr_in6 mf6cc_mcastgrp;
    mifi_t mf6cc_parent;
    unsigned char mf6cc_ttls[MAXMIFS];
};

struct sock {
    int sk_type;
};
struct net {
    void *user_ns;
};
struct mr6_table {
    struct sock *mroute6_sk;
    int mroute_do_assert;
    int mroute_do_pim;
};
struct inet_sock {
    int inet_num;
};
struct raw6_sock {
    int ip6mr_table;
};

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline struct mr6_table *ip6mr_get_table(struct net *net, int id) { return NULL; }
static inline struct raw6_sock *raw6_sk(struct sock *sk) { return NULL; }
static inline struct inet_sock *inet_sk(struct sock *sk) { return NULL; }
static inline int ns_capable(void *ns, int cap) { return 0; }
static inline void rtnl_lock(void) {}
static inline void rtnl_unlock(void) {}
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int get_user(int *val, const void *addr) { return 0; }
static inline int ip6mr_sk_init(struct mr6_table *mrt, struct sock *sk) { return 0; }
static inline int ip6mr_sk_done(struct sock *sk) { return 0; }
static inline int mif6_add(struct net *net, struct mr6_table *mrt, struct mif6ctl *vif, int flag) { return 0; }
static inline int mif6_delete(struct mr6_table *mrt, mifi_t mifi, void *arg) { return 0; }
static inline int ip6mr_mfc_delete(struct mr6_table *mrt, struct mf6cctl *mfc, int parent) { return 0; }
static inline int ip6mr_mfc_add(struct net *net, struct mr6_table *mrt, struct mf6cctl *mfc, int flag, int parent) { return 0; }
static inline int ip6mr_new_table(struct net *net, u32 id) { return 0; }