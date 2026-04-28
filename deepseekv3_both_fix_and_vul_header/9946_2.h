#include <stddef.h>
#include <string.h>

#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22
#define EFAULT 14
#define ARPT_SO_GET_INFO 0
#define ARPT_SO_GET_ENTRIES 1
#define ARPT_SO_GET_REVISION_TARGET 2
#define NFPROTO_ARP 1

struct sock;
struct net;

struct xt_get_revision {
    char name[32];
    unsigned char revision;
};

typedef void user_void;
#define __user

static inline int capable(int cap) { return 1; }
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static int get_info(struct net *net, user_void *user, int *len, int dummy) { return 0; }
static int get_entries(struct net *net, user_void *user, int *len) { return 0; }
static int copy_from_user(void *dst, const user_void *src, size_t size) { memcpy(dst, src, size); return 0; }
static void *xt_find_revision(unsigned char af, const char *name, unsigned char rev, int target, int *err) { return NULL; }
static void try_then_request_module(void *fn, const char *fmt, ...) {}
static void duprintf(const char *fmt, ...) {}