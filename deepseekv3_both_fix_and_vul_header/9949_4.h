#include <stdbool.h>
#include <stddef.h>

#define IPT_SO_GET_INFO 1
#define IPT_SO_GET_ENTRIES 2
#define IPT_SO_GET_REVISION_MATCH 3
#define IPT_SO_GET_REVISION_TARGET 4

#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22
#define EFAULT 14

#define AF_INET 2
#define XT_FUNCTION_MAXNAMELEN 32

struct sock;
struct net;

struct xt_get_revision {
    char name[XT_FUNCTION_MAXNAMELEN];
    unsigned char revision;
};

#define __user

static inline struct net *sock_net(struct sock *sk) { return NULL; }
static int get_info(struct net *net, void *user, int *len, int dummy) { return 0; }
static int get_entries(struct net *net, void *user, int *len) { return 0; }
static void *xt_find_revision(int family, const char *name, unsigned char revision, int target, int *ret) { return NULL; }
static void try_then_request_module(void *arg, const char *fmt, const char *name) {}
static void duprintf(const char *fmt, int cmd) {}
static bool capable(int cap) { return false; }
static unsigned long copy_from_user(void *to, const void *from, unsigned long n) { return 0; }