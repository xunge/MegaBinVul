#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdint.h>

#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22
#define EFAULT 14

struct xt_get_revision {
    char name[32];
    uint8_t revision;
};

struct sock;
struct net;

#define IP6T_SO_GET_INFO 1
#define IP6T_SO_GET_ENTRIES 2
#define IP6T_SO_GET_REVISION_MATCH 3
#define IP6T_SO_GET_REVISION_TARGET 4

#define __user
#define capable(x) (1)
#define sock_net(x) (NULL)
#define get_info(a,b,c,d) (0)
#define get_entries(a,b,c) (0)
#define try_then_request_module(a,b,c) (0)
#define xt_find_revision(a,b,c,d,e) (0)
#define duprintf(fmt, ...)