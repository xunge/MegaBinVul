#include <stddef.h>
#include <stdint.h>

#define HIDPCONNADD    0
#define HIDPCONNDEL    1
#define HIDPGETCONNLIST 2
#define HIDPGETCONNINFO 3

struct socket;
struct hidp_connadd_req {
    int ctrl_sock;
    int intr_sock;
    char name[128];
};

struct hidp_conndel_req {
    int bdaddr[6];
};

struct hidp_connlist_req {
    int cnum;
};

struct hidp_conninfo {
    int bdaddr[6];
};

#define BT_DBG(fmt, ...)
#define CAP_NET_ADMIN 0
#define EPERM 1
#define EFAULT 14
#define EINVAL 22

#define __user

static inline int capable(int cap) { return 0; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline struct socket *sockfd_lookup(int fd, int *err) { return NULL; }
static inline void sockfd_put(struct socket *sock) {}
static inline int hidp_connection_add(struct hidp_connadd_req *req, struct socket *ctrl_sock, struct socket *intr_sock) { return 0; }
static inline int hidp_connection_del(struct hidp_conndel_req *req) { return 0; }
static inline int hidp_get_connlist(struct hidp_connlist_req *req) { return 0; }
static inline int hidp_get_conninfo(struct hidp_conninfo *ci) { return 0; }