#include <stdint.h>

typedef uint16_t u16;
typedef uint32_t u32;

struct sock {
    uint16_t sk_protocol;
    struct sk_security_struct *sk_security;
};

struct sk_buff {
    unsigned int len;
    unsigned char *data;
};

struct nlmsghdr {
    unsigned int nlmsg_len;
    uint16_t nlmsg_type;
};

struct sk_security_struct {
    uint16_t sclass;
};

struct secclass_map {
    const char *name;
};

struct selinux_state {
};

struct task_struct {
    char comm[16];
};

extern struct selinux_state selinux_state;
extern const struct secclass_map secclass_map[];
extern struct task_struct *current;

#define NLMSG_HDRLEN ((unsigned int)0)
#define NLMSG_ALIGN(len) ((len))
#define nlmsg_total_size(len) ((len) + NLMSG_HDRLEN)
#define nlmsg_hdr(skb) ((struct nlmsghdr *)(skb)->data)
#define pr_warn_ratelimited(fmt, ...) 

#define EINVAL 1
#define ENOENT 2

static inline int enforcing_enabled(struct selinux_state *state) { return 0; }
static inline int security_get_allow_unknown(struct selinux_state *state) { return 0; }
static inline int task_pid_nr(struct task_struct *task) { return 0; }

int selinux_nlmsg_lookup(uint16_t sclass, uint16_t nlmsg_type, uint32_t *perm);
int sock_has_perm(struct sock *sk, uint32_t perm);