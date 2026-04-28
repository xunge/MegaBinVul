#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <net/ethernet.h>
#include <errno.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/queue.h>

#define LLDP_MULTICAST_ADDR { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e }
#define LLDP_TLV_ORG_DOT1 { 0x00, 0x80, 0xc2 }
#define LLDP_TLV_ORG_DOT3 { 0x00, 0x12, 0x0f }
#define LLDP_TLV_ORG_MED { 0x00, 0x12, 0xbb }
#define ETHERTYPE_LLDP 0x88cc

#define LLDP_TLV_CHASSIS_ID 1
#define LLDP_TLV_PORT_ID 2
#define LLDP_TLV_TTL 3
#define LLDP_TLV_SYSTEM_NAME 5
#define LLDP_TLV_SYSTEM_DESCR 6
#define LLDP_TLV_SYSTEM_CAP 7
#define LLDP_TLV_MGMT_ADDR 8
#define LLDP_TLV_PORT_DESCR 4
#define LLDP_TLV_END 0
#define LLDP_TLV_ORG 127

#define LLDP_MGMT_ADDR_NONE 0
#define LLDP_MGMT_IFACE_UNKNOWN 1
#define LLDP_MGMT_IFACE_IFINDEX 2

#define LLDP_TLV_DOT1_PVID 1
#define LLDP_TLV_DOT1_PPVID 2
#define LLDP_TLV_DOT1_VLANNAME 3
#define LLDP_TLV_DOT1_PI 4

#define LLDP_TLV_DOT3_LA 1
#define LLDP_TLV_DOT3_MAC 2
#define LLDP_TLV_DOT3_MFS 3
#define LLDP_TLV_DOT3_POWER 4

#define LLDP_TLV_MED_CAP 1
#define LLDP_TLV_MED_IV_HW 2
#define LLDP_TLV_MED_IV_FW 3
#define LLDP_TLV_MED_IV_SW 4
#define LLDP_TLV_MED_IV_SN 5
#define LLDP_TLV_MED_IV_MANUF 6
#define LLDP_TLV_MED_IV_MODEL 7
#define LLDP_TLV_MED_IV_ASSET 8
#define LLDP_TLV_MED_LOCATION 9
#define LLDP_TLV_MED_POLICY 10
#define LLDP_TLV_MED_MDI 11

#define LLDP_MED_CAP_IV (1 << 2)
#define LLDP_MED_APPTYPE_LAST 4
#define LLDP_MED_LOCFORMAT_LAST 7

#define LLDP_DOT3_POWER_8023AT_OFF 0
#define LLDP_DOT3_POWER_8023AT_TYPE1 1
#define LLDP_DOT3_POWER_PSE 1
#define LLDP_DOT3_POWER_PD 2

#define LLDP_MED_POW_TYPE_PSE 1
#define LLDP_MED_POW_TYPE_PD 2
#define LLDP_MED_POW_SOURCE_PRIMARY 1
#define LLDP_MED_POW_SOURCE_BACKUP 2
#define LLDP_MED_POW_SOURCE_RESERVED 3
#define LLDP_MED_POW_SOURCE_PSE 1
#define LLDP_MED_POW_SOURCE_LOCAL 2
#define LLDP_MED_POW_SOURCE_BOTH 3

#define POKE_BYTES(a, l) (memcpy(pos, a, l) ? (pos += l, 1) : 0)
#define POKE_UINT8(v) (*(pos++) = (v), 1)
#define POKE_UINT16(v) (*(uint16_t *)pos = htons(v), pos += 2, 1)
#define POKE_UINT32(v) (*(uint32_t *)pos = htonl(v), pos += 4, 1)
#define POKE_START_LLDP_TLV(t) (POKE_UINT16(((t) << 9)))
#define POKE_END_LLDP_TLV 1

struct lldpd;
struct lldpd_hardware;
struct lldpd_port;
struct lldpd_chassis;
struct lldpd_frame;
struct lldpd_mgmt;
struct lldpd_vlan;
struct lldpd_ppvid;
struct lldpd_pi;
struct lldpd_custom;
struct lldpd_med_location;
struct lldpd_med_policy;
struct lldpd_med_power;
struct lldpd_macphy;

struct lldpd_config {
    int c_cap_advertise;
};

struct lldpd {
    struct lldpd_config g_config;
};

struct lldpd_mgmt {
    u_int8_t m_family;
    u_int8_t m_addrsize;
    u_int32_t m_iface;
    u_int8_t m_addr[1];
    TAILQ_ENTRY(lldpd_mgmt) m_entries;
};

struct lldpd_chassis {
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

struct lldpd_macphy {
    u_int8_t autoneg_support;
    u_int8_t autoneg_enabled;
    u_int16_t autoneg_advertised;
    u_int16_t mau_type;
};

struct lldpd_med_location {
    u_int8_t format;
    u_int8_t *data;
    int data_len;
};

struct lldpd_med_policy {
    u_int8_t type;
    u_int8_t unknown;
    u_int8_t tagged;
    u_int16_t vid;
    u_int8_t priority;
    u_int8_t dscp;
};

struct lldpd_med_power {
    u_int8_t devicetype;
    u_int8_t source;
    u_int8_t priority;
    u_int16_t val;
};

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
    u_int8_t p_pi[1];
    TAILQ_ENTRY(lldpd_pi) p_entries;
};

struct lldpd_custom {
    u_int8_t oui[3];
    u_int8_t subtype;
    u_int8_t *oui_info;
    int oui_info_len;
    TAILQ_ENTRY(lldpd_custom) next;
};

struct lldpd_port {
    struct lldpd_chassis *p_chassis;
    char *p_descr;
    u_int16_t p_pvid;
    u_int32_t p_aggregid;
    struct lldpd_macphy p_macphy;
    u_int16_t p_mfs;
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
    struct lldpd_frame *p_lastframe;
    time_t p_lastchange;
    u_int8_t p_med_cap_enabled;
    struct lldpd_med_location p_med_location[LLDP_MED_LOCFORMAT_LAST];
    struct lldpd_med_policy p_med_policy[LLDP_MED_APPTYPE_LAST];
    struct lldpd_med_power p_med_power;
    TAILQ_HEAD(, lldpd_vlan) p_vlans;
    TAILQ_HEAD(, lldpd_ppvid) p_ppvids;
    TAILQ_HEAD(, lldpd_pi) p_pids;
    TAILQ_HEAD(, lldpd_custom) p_custom_list;
};

struct lldpd_hardware {
    struct lldpd_port h_lport;
    int h_mtu;
    char *h_ifname;
    u_int8_t h_lladdr[ETHER_ADDR_LEN];
    int h_tx_cnt;
};

struct lldpd_frame {
    int size;
    u_int8_t frame[1];
};

int lldpd_af_to_lldp_proto(u_int8_t family);
int interfaces_send_helper(struct lldpd *global, struct lldpd_hardware *hardware, char *packet, int length);
void log_warn(const char *category, const char *format, ...);