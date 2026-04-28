#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <unistd.h>
#include <stdlib.h>

#define NETNSA_MAX 3
#define NETNSA_NSID 1
#define NETNSA_FD 3

struct rtnl_handle {
    int fd;
    struct sockaddr_nl local;
    struct sockaddr_nl peer;
    __u32 seq;
    __u32 dump;
};

extern struct rtnl_handle rtnsh;

extern void netns_nsid_socket_init(void);
extern int netns_get_fd(const char *name);
extern int rtnl_talk(struct rtnl_handle *rtnl, struct nlmsghdr *n, struct nlmsghdr **answer);
extern void addattr32(struct nlmsghdr *n, int maxlen, int type, int data);
extern void parse_rtattr(struct rtattr *tb[], int max, struct rtattr *rta, int len);
extern int rta_getattr_u32(const struct rtattr *rta);