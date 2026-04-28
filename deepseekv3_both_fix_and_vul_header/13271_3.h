#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>

#define SONMP_MULTICAST_ADDR {0x01, 0x00, 0x81, 0x00, 0x01, 0x00}
#define SONMP_SIZE 12
#define ETHER_ADDR_LEN 6
#define LLC_PID_SONMP_HELLO 0x2000
#define LLDP_CHASSISID_SUBTYPE_ADDR 4
#define LLDP_PORTID_SUBTYPE_LOCAL 7
#define LLDPD_AF_IPV4 1
#define LLDPD_TTL 120

struct lldpd_hardware {
    char *h_ifname;
};

struct lldpd_mgmt {
    struct lldpd_mgmt *m_next;
};

struct lldpd_chassis {
    int c_id_subtype;
    u_int8_t *c_id;
    int c_id_len;
    char *c_name;
    char *c_descr;
    struct lldpd_mgmt *c_mgmt;
};

struct lldpd_port {
    int p_ttl;
    int p_id_subtype;
    char *p_id;
    int p_id_len;
    char *p_descr;
#ifdef ENABLE_DOT1
    struct lldpd_vlan *p_vlans;
#endif
};

struct lldpd {
    struct {
        int c_tx_interval;
        int c_tx_hold;
    } g_config;
};

struct sonmp_chassis_type {
    u_int8_t type;
    const char *description;
};
extern struct sonmp_chassis_type sonmp_chassis_types[];

#define TAILQ_INIT(head) do { \
    *(head) = NULL; \
} while (0)

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->m_next = NULL; \
    if (*(head) == NULL) { \
        *(head) = (elm); \
    } else { \
        struct lldpd_mgmt *last = *(head); \
        while (last->m_next != NULL) \
            last = last->m_next; \
        last->m_next = (elm); \
    } \
} while (0)

#define PEEK_CMP(addr, len) memcmp(pos, addr, len)
#define PEEK_DISCARD(len) (pos += (len))
#define PEEK_DISCARD_UINT16 (pos += 2)
#define PEEK_UINT16 (*(u_int16_t*)pos)
#define PEEK_BYTES(ptr, len) do { memcpy(ptr, pos, len); pos += len; } while (0)
#define PEEK_UINT8 (*(u_int8_t*)pos++)

void log_debug(const char *, const char *, ...);
void log_warn(const char *, const char *, ...);
void log_warnx(const char *, const char *, ...);
int asprintf(char **, const char *, ...);
struct lldpd_mgmt *lldpd_alloc_mgmt(int, struct in_addr *, size_t, int);
void lldpd_chassis_cleanup(struct lldpd_chassis *, int);
void lldpd_port_cleanup(struct lldpd_port *, int);