#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22
#define EBT_SO_SET_ENTRIES 0
#define EBT_SO_SET_COUNTERS 1

struct sock;
struct net;

typedef void* user_ptr_t;

static int do_replace(struct net *net, user_ptr_t user, unsigned int len);
static int update_counters(struct net *net, user_ptr_t user, unsigned int len);
static inline struct net *sock_net(struct sock *sk);

#define __user
#define capable(x) (1)