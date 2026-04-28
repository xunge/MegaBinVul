#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_POLICY_RECURSION_DEPTH 10
#define EINVAL 22
#define NL_VALIDATE_MAXTYPE 1
#define NL_VALIDATE_TRAILING 2

typedef uint16_t u16;

struct nlattr {
    u16 nla_len;
    u16 nla_type;
};

struct nla_policy;
struct netlink_ext_ack;

#define nla_for_each_attr(pos, head, len, rem) \
    for (pos = head, rem = len; \
         rem >= (int)sizeof(struct nlattr); \
         pos = (struct nlattr *)((char *)pos + NLA_ALIGN(pos->nla_len)), \
         rem -= NLA_ALIGN(pos->nla_len))

#define NLA_ALIGN(len) (((len) + 3) & ~3)

static inline u16 nla_type(const struct nlattr *nla)
{
    return nla->nla_type;
}

#define NL_SET_ERR_MSG(extack, msg) do {} while (0)
#define NL_SET_ERR_MSG_ATTR(extack, attr, msg) do {} while (0)

#define pr_warn_ratelimited(fmt, ...) printf(fmt, ##__VA_ARGS__)

struct task_struct {
    char comm[16];
};

extern struct task_struct *current;

static inline int validate_nla(const struct nlattr *nla, int maxtype,
                             const struct nla_policy *policy,
                             unsigned int validate,
                             struct netlink_ext_ack *extack,
                             ...)
{
    return 0;
}

static inline int unlikely(int x) { return x; }