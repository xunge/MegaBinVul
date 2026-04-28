#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <net/ethernet.h>
#include <errno.h>

#define LLDP_MULTICAST_ADDR "\x01\x80\xc2\x00\x00\x0e"
#define LLDP_TLV_ORG_DOT1 "\x00\x80\xc2"
#define LLDP_TLV_ORG_DOT3 "\x00\x12\x0f"
#define LLDP_TLV_ORG_MED "\x00\x12\xbb"
#define LLDP_TLV_ORG_DCBX "\x00\x1b\x21"

#define ETHER_ADDR_LEN 6
#define ETHERTYPE_LLDP 0x88cc

#define LLDP_TLV_END 0
#define LLDP_TLV_CHASSIS_ID 1
#define LLDP_TLV_PORT_ID 2
#define LLDP_TLV_TTL 3
#define LLDP_TLV_PORT_DESCR 4
#define LLDP_TLV_SYSTEM_NAME 5
#define LLDP_TLV_SYSTEM_DESCR 6
#define LLDP_TLV_SYSTEM_CAP 7
#define LLDP_TLV_MGMT_ADDR 8
#define LLDP_TLV_ORG 127

#define LLDP_MGMT_IFACE_IFINDEX 1

#define PEEK_CMP(a, b) memcmp(pos, a, b)
#define PEEK_DISCARD(b) (pos += (b))
#define PEEK_UINT16 (ntohs(*(u_int16_t*)pos), pos += 2)
#define PEEK_UINT32 (ntohl(*(u_int32_t*)pos), pos += 4)
#define PEEK_UINT8 (*(u_int8_t*)pos, pos += 1)
#define PEEK_BYTES(a, b) (memcpy(a, pos, b), pos += (b))
#define PEEK_SAVE(a) (a = pos)
#define PEEK_DISCARD_UINT8 (pos += 1)

#define CHECK_TLV_SIZE(a, b) \
    if (tlv_size < a) { \
        log_warnx("lldp", "tlv " b " too short received on %s", hardware->h_ifname); \
        goto malformed; \
    }

struct lldpd;
struct lldpd_hardware;
struct lldpd_chassis;
struct lldpd_port;
struct lldpd_vlan;
struct lldpd_ppvid;
struct lldpd_pi;
struct lldpd_mgmt;
struct lldpd_custom;

#define TAILQ_HEAD(name, type) \
    struct name { \
        struct type *tqh_first; \
        struct type **tqh_last; \
    }
#define TAILQ_ENTRY(type) \
    struct { \
        struct type *tqe_next; \
        struct type **tqe_prev; \
    }
#define TAILQ_INIT(head) \
    do { \
        (head)->tqh_first = NULL; \
        (head)->tqh_last = &(head)->tqh_first; \
    } while (0)
#define TAILQ_INSERT_TAIL(head, elm, field) \
    do { \
        (elm)->field.tqe_next = NULL; \
        (elm)->field.tqe_prev = (head)->tqh_last; \
        *(head)->tqh_last = (elm); \
        (head)->tqh_last = &(elm)->field.tqe_next; \
    } while (0)

enum {
    LLDPD_AF_UNSPEC = 0,
    LLDPD_AF_IPV4,
    LLDPD_AF_IPV6
};

enum {
    LLDP_DOT3_POWER_PSE,
    LLDP_DOT3_POWER_PD,
    LLDP_DOT3_POWER_8023AT_OFF,
    LLDP_DOT3_POWER_8023AT_TYPE1,
    LLDP_DOT3_POWER_8023AT_TYPE2
};

enum {
    LLDP_MED_POW_TYPE_PSE,
    LLDP_MED_POW_TYPE_PD,
    LLDP_MED_POW_TYPE_RESERVED
};

enum {
    LLDP_MED_POW_SOURCE_UNKNOWN,
    LLDP_MED_POW_SOURCE_PRIMARY,
    LLDP_MED_POW_SOURCE_BACKUP,
    LLDP_MED_POW_SOURCE_RESERVED,
    LLDP_MED_POW_SOURCE_PSE,
    LLDP_MED_POW_SOURCE_LOCAL,
    LLDP_MED_POW_SOURCE_BOTH
};

enum {
    LLDP_MED_POW_PRIO_UNKNOWN,
    LLDP_MED_POW_PRIO_CRITICAL,
    LLDP_MED_POW_PRIO_HIGH,
    LLDP_MED_POW_PRIO_LOW
};

enum {
    LLDP_MED_APPTYPE_LAST = 8
};

enum {
    LLDP_MED_LOCFORMAT_LAST = 6
};

enum {
    LLDP_MED_CAP_CAP = 1,
    LLDP_MED_CAP_POLICY = 2,
    LLDP_MED_CAP_LOCATION = 4,
    LLDP_MED_CAP_MDI_PSE = 8,
    LLDP_MED_CAP_MDI_PD = 16,
    LLDP_MED_CAP_IV = 32
};

struct lldpd_mgmt {
    TAILQ_ENTRY(lldpd_mgmt) m_entries;
    int m_family;
    void *m_addr;
    size_t m_addrsize;
    u_int32_t m_ifindex;
};

struct lldpd_vlan {
    TAILQ_ENTRY(lldpd_vlan) v_entries;
    u_int16_t v_vid;
    char *v_name;
};

struct lldpd_ppvid {
    TAILQ_ENTRY(lldpd_ppvid) p_entries;
    u_int8_t p_cap_status;
    u_int16_t p_ppvid;
};

struct lldpd_pi {
    TAILQ_ENTRY(lldpd_pi) p_entries;
    u_int8_t p_pi_len;
    char *p_pi;
};

struct lldpd_custom {
    TAILQ_ENTRY(lldpd_custom) next;
    u_int8_t oui[3];
    u_int8_t subtype;
    u_int8_t *oui_info;
    size_t oui_info_len;
};

struct lldpd_port {
    u_int8_t p_id_subtype;
    char *p_id;
    size_t p_id_len;
    char *p_descr;
    u_int16_t p_ttl;
    u_int16_t p_mfs;
    u_int16_t p_pvid;
    u_int32_t p_aggregid;
    struct {
        int autoneg_support;
        int autoneg_enabled;
        u_int16_t autoneg_advertised;
        u_int16_t mau_type;
    } p_macphy;
    struct {
        int devicetype;
        int supported;
        int enabled;
        int paircontrol;
        u_int8_t pairs;
        u_int8_t class;
        int powertype;
        int source;
        int priority;
        u_int16_t requested;
        u_int16_t allocated;
    } p_power;
    struct {
        int devicetype;
        int source;
        int priority;
        u_int16_t val;
    } p_med_power;
    struct {
        int type;
        int unknown;
        int tagged;
        u_int16_t vid;
        int priority;
        int dscp;
    } p_med_policy[LLDP_MED_APPTYPE_LAST];
    struct {
        int format;
        char *data;
        size_t data_len;
    } p_med_location[LLDP_MED_LOCFORMAT_LAST];
    u_int8_t p_med_cap_enabled;
    TAILQ_HEAD(, lldpd_vlan) p_vlans;
    TAILQ_HEAD(, lldpd_ppvid) p_ppvids;
    TAILQ_HEAD(, lldpd_pi) p_pids;
    TAILQ_HEAD(, lldpd_custom) p_custom_list;
};

struct lldpd_chassis {
    u_int8_t c_id_subtype;
    char *c_id;
    size_t c_id_len;
    char *c_name;
    char *c_descr;
    u_int16_t c_ttl;
    u_int16_t c_cap_available;
    u_int16_t c_cap_enabled;
    u_int16_t c_med_cap_available;
    u_int8_t c_med_type;
    char *c_med_hw;
    char *c_med_fw;
    char *c_med_sw;
    char *c_med_sn;
    char *c_med_manuf;
    char *c_med_model;
    char *c_med_asset;
    TAILQ_HEAD(, lldpd_mgmt) c_mgmt;
};

struct lldpd_hardware {
    char *h_ifname;
    int h_rx_unrecognized_cnt;
};

void log_debug(const char *, const char *, ...);
void log_warn(const char *, const char *, ...);
void log_warnx(const char *, const char *, ...);
void log_info(const char *, const char *, ...);
struct lldpd_mgmt *lldpd_alloc_mgmt(int, u_int8_t *, u_int8_t, u_int32_t);
void lldpd_chassis_cleanup(struct lldpd_chassis *, int);
void lldpd_port_cleanup(struct lldpd_port *, int);
int lldpd_af_from_lldp_proto(u_int8_t);