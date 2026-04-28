#include <sys/types.h>
#include <sys/queue.h>
#include <net/ethernet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define LLDP_MULTICAST_ADDR "\x01\x80\xc2\x00\x00\x0e"
#define LLDP_TLV_ORG_DOT1 "\x00\x80\xc2"
#define LLDP_TLV_ORG_DOT3 "\x00\x12\x0f"
#define LLDP_TLV_ORG_MED "\x00\x12\xbb"
#define LLDP_TLV_ORG_DCBX "\x00\x1b\x21"

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

#define LLDP_TLV_DOT1_VLANNAME 1
#define LLDP_TLV_DOT1_PVID 2
#define LLDP_TLV_DOT1_PPVID 3
#define LLDP_TLV_DOT1_PI 4

#define LLDP_TLV_DOT3_MAC 1
#define LLDP_TLV_DOT3_LA 2
#define LLDP_TLV_DOT3_MFS 3
#define LLDP_TLV_DOT3_POWER 4

#define LLDP_TLV_MED_CAP 1
#define LLDP_TLV_MED_POLICY 2
#define LLDP_TLV_MED_LOCATION 3
#define LLDP_TLV_MED_MDI 4
#define LLDP_TLV_MED_IV_HW 5
#define LLDP_TLV_MED_IV_SW 6
#define LLDP_TLV_MED_IV_FW 7
#define LLDP_TLV_MED_IV_SN 8
#define LLDP_TLV_MED_IV_MANUF 9
#define LLDP_TLV_MED_IV_MODEL 10
#define LLDP_TLV_MED_IV_ASSET 11

#define LLDP_MGMT_IFACE_IFINDEX 1

#define LLDPD_AF_UNSPEC 0

#define LLDP_DOT3_POWER_PSE 1
#define LLDP_DOT3_POWER_PD 2
#define LLDP_DOT3_POWER_8023AT_OFF 0
#define LLDP_DOT3_POWER_8023AT_TYPE1 1
#define LLDP_DOT3_POWER_8023AT_TYPE2 2

#define LLDP_MED_POW_TYPE_PSE 1
#define LLDP_MED_POW_TYPE_PD 2
#define LLDP_MED_POW_TYPE_RESERVED 3
#define LLDP_MED_POW_SOURCE_UNKNOWN 0
#define LLDP_MED_POW_SOURCE_PRIMARY 1
#define LLDP_MED_POW_SOURCE_BACKUP 2
#define LLDP_MED_POW_SOURCE_RESERVED 3
#define LLDP_MED_POW_SOURCE_PSE 1
#define LLDP_MED_POW_SOURCE_LOCAL 2
#define LLDP_MED_POW_SOURCE_BOTH 3
#define LLDP_MED_POW_PRIO_UNKNOWN 0
#define LLDP_MED_POW_PRIO_CRITICAL 1
#define LLDP_MED_POW_PRIO_HIGH 2
#define LLDP_MED_POW_PRIO_LOW 3

#define LLDP_MED_CAP_CAP 0x01
#define LLDP_MED_CAP_POLICY 0x02
#define LLDP_MED_CAP_LOCATION 0x04
#define LLDP_MED_CAP_MDI_PSE 0x08
#define LLDP_MED_CAP_MDI_PD 0x10
#define LLDP_MED_CAP_IV 0x20

#define LLDP_MED_APPTYPE_LAST 4
#define LLDP_MED_LOCFORMAT_LAST 6

#define PEEK_CMP(a, l) memcmp(pos, a, l)
#define PEEK_DISCARD(l) pos += l
#define PEEK_UINT8 (*pos++)
#define PEEK_UINT16 (pos += 2, (pos[-2] << 8) + pos[-1])
#define PEEK_UINT32 (pos += 4, (pos[-4] << 24) + (pos[-3] << 16) + (pos[-2] << 8) + pos[-1])
#define PEEK_BYTES(b, l) do { memcpy(b, pos, l); pos += l; } while (0)
#define PEEK_SAVE(p) (p = pos)
#define PEEK_DISCARD_UINT8 PEEK_UINT8

#define CHECK_TLV_SIZE(s, t) \
    if (tlv_size < s) { \
        log_warnx("lldp", "tlv " t " too short received on %s", hardware->h_ifname); \
        goto malformed; \
    }

struct lldpd;
struct lldpd_hardware;

struct lldpd_vlan {
    u_int16_t v_vid;
    char *v_name;
    TAILQ_ENTRY(lldpd_vlan) v_entries;
};

struct lldpd_ppvid {
    u_int8_t p_cap_status;
    u_int16_t p_ppvid;
    TAILQ_ENTRY(lldpd_ppvid) p_entries;
};

struct lldpd_pi {
    u_int8_t p_pi_len;
    char *p_pi;
    TAILQ_ENTRY(lldpd_pi) p_entries;
};

struct lldpd_mgmt {
    int m_family;
    u_int8_t *m_addr;
    int m_addrsize;
    u_int32_t m_iface;
    TAILQ_ENTRY(lldpd_mgmt) m_entries;
};

struct lldpd_custom {
    u_int8_t oui[3];
    u_int8_t subtype;
    u_int8_t *oui_info;
    int oui_info_len;
    TAILQ_ENTRY(lldpd_custom) next;
};

struct lldpd_chassis {
    u_int8_t c_id_subtype;
    char *c_id;
    int c_id_len;
    u_int16_t c_ttl;
    char *c_name;
    char *c_descr;
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

struct lldpd_port {
    u_int8_t p_id_subtype;
    char *p_id;
    int p_id_len;
    char *p_descr;
    u_int16_t p_mfs;
    u_int32_t p_aggregid;
    u_int16_t p_pvid;
    struct {
        u_int8_t autoneg_support;
        u_int8_t autoneg_enabled;
        u_int16_t autoneg_advertised;
        u_int16_t mau_type;
    } p_macphy;
    struct {
        u_int8_t devicetype;
        u_int8_t supported;
        u_int8_t enabled;
        u_int8_t paircontrol;
        u_int8_t pairs;
        u_int8_t class;
        u_int8_t powertype;
        u_int8_t source;
        u_int8_t priority;
        u_int16_t requested;
        u_int16_t allocated;
    } p_power;
    struct {
        u_int8_t devicetype;
        u_int8_t source;
        u_int8_t priority;
        u_int16_t val;
    } p_med_power;
    struct {
        u_int8_t type;
        u_int8_t unknown;
        u_int8_t tagged;
        u_int16_t vid;
        u_int8_t priority;
        u_int8_t dscp;
    } p_med_policy[LLDP_MED_APPTYPE_LAST];
    struct {
        char *data;
        int data_len;
        u_int8_t format;
    } p_med_location[LLDP_MED_LOCFORMAT_LAST];
    u_int8_t p_med_cap_enabled;
    TAILQ_HEAD(, lldpd_vlan) p_vlans;
    TAILQ_HEAD(, lldpd_ppvid) p_ppvids;
    TAILQ_HEAD(, lldpd_pi) p_pids;
    TAILQ_HEAD(, lldpd_custom) p_custom_list;
};

struct lldpd_hardware {
    char *h_ifname;
    int h_rx_unrecognized_cnt;
};

void log_debug(const char *, const char *, ...);
void log_warn(const char *, const char *, ...);
void log_warnx(const char *, const char *, ...);
void log_info(const char *, const char *, ...);
int lldpd_af_from_lldp_proto(int);
struct lldpd_mgmt *lldpd_alloc_mgmt(int, u_int8_t *, int, u_int32_t);
void lldpd_chassis_cleanup(struct lldpd_chassis *, int);
void lldpd_port_cleanup(struct lldpd_port *, int);