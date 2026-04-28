#include <stddef.h>

#define ERANGE 34

struct nlattr {
    unsigned short nla_len;
    unsigned short nla_type;
};

struct nla_policy;
struct netlink_ext_ack;

#define NLA_HDRLEN ((int)sizeof(struct nlattr))

#define nla_len(attr) ((attr)->nla_len)
#define nla_data(attr) ((void *)((char *)(attr) + NLA_HDRLEN))

#define nla_for_each_attr(pos, head, len, rem) \
    for (pos = head, rem = len; \
         rem >= NLA_HDRLEN && \
         pos->nla_len >= NLA_HDRLEN && \
         pos->nla_len <= rem; \
         rem -= pos->nla_len, \
         pos = (struct nlattr *)((char *)pos + pos->nla_len))

#define NL_SET_ERR_MSG_ATTR(extack, attr, msg)

int __nla_validate_parse(const void *data, int len, int maxtype,
                        const struct nla_policy *policy,
                        unsigned int validate,
                        struct netlink_ext_ack *extack,
                        void *null, unsigned int depth);
int __nla_validate(const void *data, int len, int maxtype,
                  const struct nla_policy *policy,
                  unsigned int validate,
                  struct netlink_ext_ack *extack);