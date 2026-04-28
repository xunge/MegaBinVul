#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define CDP_MULTICAST_ADDR {0x01, 0x00, 0x0c, 0xcc, 0xcc, 0xcc}
#define ETHER_ADDR_LEN 6
#define LLC_PID_CDP 0x2000
#define LLC_PID_DRIP 0x2001
#define LLC_PID_PAGP 0x2004
#define LLC_PID_PVSTP 0x2005
#define LLC_PID_UDLD 0x2006
#define LLC_PID_VTP 0x2007
#define LLC_PID_DTP 0x2008
#define LLC_PID_STP 0x2009

#define CDP_TLV_CHASSIS 0x0001
#define CDP_TLV_ADDRESSES 0x0002
#define CDP_TLV_PORT 0x0003
#define CDP_TLV_CAPABILITIES 0x0004
#define CDP_TLV_SOFTWARE 0x0005
#define CDP_TLV_PLATFORM 0x0006
#define CDP_TLV_NATIVEVLAN 0x000a
#define CDP_TLV_POWER_AVAILABLE 0x0010

#define CDP_ADDRESS_PROTO_IP 0xcc
#define CDP_CAP_ROUTER 0x01

#define LLDP_CHASSISID_SUBTYPE_LOCAL 7
#define LLDP_PORTID_SUBTYPE_IFNAME 5
#define LLDPD_AF_IPV4 1
#define LLDP_CAP_ROUTER 0x10
#define LLDP_CAP_BRIDGE 0x08
#define LLDP_CAP_REPEATER 0x04
#define LLDP_CAP_STATION 0x01

#define LLDP_DOT3_POWER_PSE 1
#define LLDP_DOT3_POWER_8023AT_TYPE2 2

#define CDP_CLASS_3_MAX_PSE_POE 15400
#define CDP_SWITCH_POE_CLASS_4_OFFSET 4000
#define CDP_SWITCH_POE_CLASS_3_OFFSET 15400

#define CHECK_TLV_SIZE(size, name) \
    if (tlv_len < size) { \
        log_warnx("cdp", "too short " name " TLV received on %s", hardware->h_ifname); \
        goto malformed; \
    }

#define PEEK_CMP(addr, len) memcmp(pos, addr, len)
#define PEEK_RESTORE(ptr) pos = ptr
#define PEEK_SAVE(ptr) (ptr = pos)
#define PEEK_DISCARD(len) pos += len
#define PEEK_DISCARD_UINT8 pos += 1
#define PEEK_DISCARD_UINT16 pos += 2
#define PEEK_UINT8 (*pos++)
#define PEEK_UINT16 (pos += 2, ntohs(*(u_int16_t *)(pos - 2)))
#define PEEK_UINT32 (pos += 4, ntohl(*(u_int32_t *)(pos - 4)))
#define PEEK_BYTES(dst, len) do { memcpy(dst, pos, len); pos += len; } while (0)

struct lldpd;
struct lldpd_hardware;
struct lldpd_chassis;
struct lldpd_port;
struct lldpd_mgmt;
struct lldpd_vlan;

struct lldpd_port {
    char *p_id;
    int p_id_len;
    int p_id_subtype;
    char *p_descr;
    int p_ttl;
    struct {
        int allocated;
        int supported;
        int enabled;
        int devicetype;
        int powertype;
        int requested;
    } p_power;
    struct {
        int management_id;
    } p_cdp_power;
    int p_pvid;
    struct {
        struct lldpd_vlan *tqh_first;
    } p_vlans;
};

struct lldpd_chassis {
    char *c_name;
    char *c_id;
    int c_id_len;
    int c_id_subtype;
    char *c_descr;
    int c_cap_enabled;
    int c_cap_available;
    struct {
        struct lldpd_mgmt *tqh_first;
    } c_mgmt;
};

struct lldpd_hardware {
    char *h_ifname;
    struct {
        struct lldpd_port p_power;
    } h_lport;
    int h_rx_unrecognized_cnt;
};

struct lldpd_mgmt {
    struct lldpd_mgmt *m_entries;
};

struct lldpd_vlan {
    int v_vid;
    char *v_name;
    struct lldpd_vlan *v_entries;
};

#define TAILQ_INIT(head) do { (head)->tqh_first = NULL; } while (0)
#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field = NULL; \
    if ((head)->tqh_first == NULL) { \
        (head)->tqh_first = (elm); \
    } else { \
        struct lldpd_mgmt *tq = (head)->tqh_first; \
        while (tq->field != NULL) tq = tq->field; \
        tq->field = (elm); \
    } \
} while (0)

void log_debug(const char *, const char *, ...);
void log_warn(const char *, const char *, ...);
void log_warnx(const char *, const char *, ...);
void log_info(const char *, const char *, ...);
struct lldpd_mgmt *lldpd_alloc_mgmt(int, struct in_addr *, int, int);
void lldpd_chassis_cleanup(struct lldpd_chassis *, int);
void lldpd_port_cleanup(struct lldpd_port *, int);