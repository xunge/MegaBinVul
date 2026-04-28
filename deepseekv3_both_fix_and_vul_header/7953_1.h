#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define TIPC_NLA_LINK_MAX 3
#define TIPC_NLA_LINK 1
#define TIPC_NLA_LINK_DEST 2
#define TIPC_NLA_LINK_UP 3
#define TIPC_NLA_LINK_NAME 4
#define TIPC_TLV_LINK_INFO 5
#define TIPC_MAX_LINK_NAME 32

struct tipc_nl_compat_msg {
    void *rep;
};

struct tipc_link_info {
    uint32_t dest;
    uint32_t up;
    char str[TIPC_MAX_LINK_NAME];
};

struct nlattr {
    uint16_t nla_len;
    uint16_t nla_type;
};

int nla_parse_nested(struct nlattr *tb[], int maxtype, struct nlattr *nla, void *arg);
int nla_get_flag(struct nlattr *nla);
void *nla_data(const struct nlattr *nla);
int tipc_add_tlv(void *rep, int type, void *data, int len);