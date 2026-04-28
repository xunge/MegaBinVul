#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdio.h>

#define ETHER_ADDR_LEN 6
#define CDP_MULTICAST_ADDR {0x01, 0x00, 0x0c, 0xcc, 0xcc, 0xcc}
#define LLC_PID_CDP 0x2000
#define LLC_PID_DRIP 0x2001
#define LLC_PID_PAGP 0x2002
#define LLC_PID_PVSTP 0x2003
#define LLC_PID_UDLD 0x2004
#define LLC_PID_VTP 0x2005
#define LLC_PID_DTP 0x2006
#define LLC_PID_STP 0x2007
#define CDP_TLV_CHASSIS 0x0001
#define CDP_TLV_ADDRESSES 0x0002
#define CDP_TLV_PORT 0x0003
#define CDP_TLV_CAPABILITIES 0x0004
#define CDP_TLV_SOFTWARE 0x0005
#define CDP_TLV_PLATFORM 0x0006
#define CDP_TLV_NATIVEVLAN 0x000a
#define CDP_ADDRESS_PROTO_IP 0xcc
#define CDP_CAP_ROUTER 0x0001
#define LLDPD_AF_IPV4 1
#define LLDP_CHASSISID_SUBTYPE_LOCAL 7
#define LLDP_PORTID_SUBTYPE_IFNAME 5
#define LLDP_CAP_ROUTER 0x10
#define LLDP_CAP_BRIDGE 0x08
#define LLDP_CAP_REPEATER 0x04
#define LLDP_CAP_STATION 0x01

#define PEEK_CMP(a, l) memcmp(pos, a, l)
#define PEEK_RESTORE(p) pos = p
#define PEEK_SAVE(p) (p = pos)
#define PEEK_DISCARD(l) (pos += l, length -= l)
#define PEEK_UINT8 (*(u_int8_t*)pos)
#define PEEK_UINT16 (ntohs(*(u_int16_t*)pos))
#define PEEK_UINT32 (ntohl(*(u_int32_t*)pos))
#define PEEK_BYTES(d, l) do { memcpy(d, pos, l); pos += l; length -= l; } while (0)
#define PEEK_DISCARD_UINT8 PEEK_DISCARD(1)
#define PEEK_DISCARD_UINT16 PEEK_DISCARD(2)
#define CHECK_TLV_SIZE(s, t) do { if (tlv_len < s) { log_warn("cdp", "too short " t " TLV received on %s", hardware->h_ifname); goto malformed; } } while (0)

struct lldpd;
struct lldpd_hardware {
    char *h_ifname;
    int h_rx_unrecognized_cnt;
};

struct lldpd_mgmt {
    int m_family;
    struct in_addr m_addr;
    int m_addrsize;
    int m_iface;
    struct lldpd_mgmt *m_entries_next;
    struct lldpd_mgmt **m_entries_prev;
};

struct lldpd_vlan {
    int v_vid;
    char *v_name;
    struct lldpd_vlan *v_entries_next;
    struct lldpd_vlan **v_entries_prev;
};

struct lldpd_chassis {
    char *c_name;
    char *c_descr;
    char *c_id;
    int c_id_len;
    int c_id_subtype;
    int c_ttl;
    int c_cap_enabled;
    int c_cap_available;
    struct lldpd_mgmt *c_mgmt;
};

struct lldpd_port {
    char *p_id;
    int p_id_len;
    int p_id_subtype;
    char *p_descr;
    int p_pvid;
    struct lldpd_vlan *p_vlans;
};

#define TAILQ_INIT(head) do { \
    *(head) = NULL; \
} while (0)

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field##_next = NULL; \
    if (*(head) == NULL) { \
        *(head) = (elm); \
        (elm)->field##_prev = (head); \
    } else { \
        typeof(*(head)) last = *(head); \
        while (last->field##_next != NULL) \
            last = last->field##_next; \
        last->field##_next = (elm); \
        (elm)->field##_prev = &(last->field##_next); \
    } \
} while (0)

void log_debug(const char *, const char *, ...);
void log_warn(const char *, const char *, ...);
void log_warnx(const char *, const char *, ...);
void log_info(const char *, const char *, ...);
struct lldpd_mgmt* lldpd_alloc_mgmt(int, struct in_addr*, int, int);
void lldpd_chassis_cleanup(struct lldpd_chassis*, int);
void lldpd_port_cleanup(struct lldpd_port*, int);