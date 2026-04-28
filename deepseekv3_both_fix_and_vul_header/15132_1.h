#include <stdint.h>
#include <stdio.h>

typedef uint16_t u16;
typedef uint32_t u32;
typedef uint8_t u8;

struct sock {
    struct sk_security_struct *sk_security;
    int sk_protocol;
};

struct sk_security_struct {
    u32 sid;
    u16 sclass;
};

struct avc_audit_data {
    union {
        struct {
            u16 dport;
        } net;
    } u;
};

#define SECCLASS_UDP_SOCKET 1
#define SECCLASS_TCP_SOCKET 2
#define SECCLASS_DCCP_SOCKET 3
#define SECCLASS_NETIF 4
#define SECCLASS_NODE 5

#define NETIF__UDP_SEND 1
#define NETIF__TCP_SEND 2
#define NETIF__DCCP_SEND 3
#define NETIF__RAWIP_SEND 4

#define NODE__UDP_SEND 1
#define NODE__TCP_SEND 2
#define NODE__DCCP_SEND 3
#define NODE__RAWIP_SEND 4

#define UDP_SOCKET__SEND_MSG 1
#define TCP_SOCKET__SEND_MSG 2
#define DCCP_SOCKET__SEND_MSG 3

#define KERN_WARNING ""

#define unlikely(x) (x)

static inline u16 ntohs(u16 x) {
    return ((x & 0xff) << 8) | ((x & 0xff00) >> 8);
}

int sel_netif_sid(int ifindex, u32 *sid);
int sel_netnode_sid(char *addrp, u16 family, u32 *sid);
int sel_netport_sid(u8 protocol, u16 port, u32 *sid);
int avc_has_perm(u32 ssid, u32 tsid, u16 tclass, u32 requested, struct avc_audit_data *auditdata);