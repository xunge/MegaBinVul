#include <stddef.h>

struct nlattr;
struct nla_policy;
struct netlink_ext_ack;

int __nla_validate_parse(const struct nlattr *head, int len, int maxtype,
                        const struct nla_policy *policy, unsigned int validate,
                        struct netlink_ext_ack *extack, void *null1, ...);