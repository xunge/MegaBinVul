#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <sys/queue.h>

#define SONMP_MULTICAST_ADDR { 0x01, 0x00, 0x81, 0x00, 0x01, 0x00 }
#define SONMP_SIZE 32
#define ETHER_ADDR_LEN 6
#define LLC_PID_SONMP_HELLO 0x2000
#define LLDP_CHASSISID_SUBTYPE_ADDR 4
#define LLDP_PORTID_SUBTYPE_LOCAL 7
#define LLDPD_AF_IPV4 1
#define LLDPD_TTL 120

#define PEEK_CMP(a, l) memcmp(pos, a, l)
#define PEEK_DISCARD(l) pos += l
#define PEEK_DISCARD_UINT16 PEEK_DISCARD(2)
#define PEEK_UINT16 ntohs(*(u_int16_t *)pos)
#define PEEK_UINT8 *pos
#define PEEK_BYTES(d, l) do { memcpy(d, pos, l); pos += l; } while (0)

struct lldpd {
    struct {
        int c_tx_interval;
        int c_tx_hold;
    } g_config;
};

struct lldpd_hardware {
    char h_ifname[32];
};

struct lldpd_chassis {
    int c_id_subtype;
    u_int8_t *c_id;
    int c_id_len;
    char *c_name;
    char *c_descr;
    int c_ttl;
    TAILQ_HEAD(, lldpd_mgmt) c_mgmt;
};

struct lldpd_port {
    int p_id_subtype;
    char *p_id;
    int p_id_len;
    char *p_descr;
#ifdef ENABLE_DOT1
    TAILQ_HEAD(, lldpd_vlan) p_vlans;
#endif
};

struct lldpd_mgmt {
    TAILQ_ENTRY(lldpd_mgmt) m_entries;
};

struct sonmp_chassis_type {
    u_int8_t type;
    char *description;
};

extern struct sonmp_chassis_type sonmp_chassis_types[];

void lldpd_chassis_cleanup(struct lldpd_chassis *, int);
void lldpd_port_cleanup(struct lldpd_port *, int);
struct lldpd_mgmt *lldpd_alloc_mgmt(int, void *, size_t, int);

void log_debug(const char *, const char *, ...);
void log_warn(const char *, const char *, ...);
void log_warnx(const char *, const char *, ...);