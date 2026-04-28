#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

struct net_device;
struct ifreq {
    void *ifr_data;
};

struct ipddp_route {
    unsigned int ip;
    unsigned int at;
    unsigned int flags;
};

extern int ipddp_route_lock;
extern int ipddp_create(struct ipddp_route *);
extern int ipddp_delete(struct ipddp_route *);
extern struct ipddp_route *__ipddp_find_route(struct ipddp_route *);

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EFAULT 2
#define ENOENT 3
#define EINVAL 4
#define SIOCADDIPDDPRT 0
#define SIOCFINDIPDDPRT 1
#define SIOCDELIPDDPRT 2
#define __user

static inline int capable(int cap) { return 1; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline void spin_lock_bh(int *lock) {}
static inline void spin_unlock_bh(int *lock) {}