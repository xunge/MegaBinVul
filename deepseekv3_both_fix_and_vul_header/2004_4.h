#include <stddef.h>
#include <stdint.h>

#define BNEPCONNADD 1
#define BNEPCONNDEL 2
#define BNEPGETCONNLIST 3
#define BNEPGETCONNINFO 4

#define CAP_NET_ADMIN 0
#define EACCES 1
#define EFAULT 2
#define EBADFD 3
#define EINVAL 4

#define BT_CONNECTED 1

#define BT_DBG(fmt, ...)

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
};

struct bnep_connlist_req {
    int cnum;
};

struct bnep_connadd_req {
    int sock;
    char device[16];
};

struct bnep_conndel_req {
    int dummy;
};

struct bnep_conninfo {
    int dummy;
};

#define __user
typedef void* user_ptr_t;

static inline int capable(int cap) { return 0; }
static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { return 0; }
static inline struct socket *sockfd_lookup(int fd, int *err) { return NULL; }
static inline void sockfd_put(struct socket *sock) {}
static inline int bnep_add_connection(struct bnep_connadd_req *req, struct socket *sock) { return 0; }
static inline int bnep_del_connection(struct bnep_conndel_req *req) { return 0; }
static inline int bnep_get_connlist(struct bnep_connlist_req *req) { return 0; }
static inline int bnep_get_conninfo(struct bnep_conninfo *ci) { return 0; }