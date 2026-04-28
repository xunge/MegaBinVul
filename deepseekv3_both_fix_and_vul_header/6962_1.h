#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define OVS_UNUSED __attribute__((__unused__))

#define ETH_ADDR_LEN 6
#define ETHERTYPE_LLDP 0x88cc

#define LLDP_MULTICAST_ADDR { 0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e }
#define LLDP_TLV_ORG_DOT1 { 0x00, 0x80, 0xc2 }
#define LLDP_TLV_ORG_DOT3 { 0x00, 0x12, 0x0f }
#define LLDP_TLV_ORG_MED { 0x00, 0x12, 0xbb }
#define LLDP_TLV_ORG_AVAYA { 0x00, 0x1d, 0xb1 }
#define LLDP_TLV_ORG_DCBX { 0x00, 0x1d, 0xb7 }

#define LLDP_TLV_AA_ISID_VLAN_DIGEST_LENGTH 32

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

#define LLDP_TLV_AA_ELEMENT_SUBTYPE 1
#define LLDP_TLV_AA_ISID_VLAN_ASGNS_SUBTYPE 2

#define LLDP_MGMT_IFACE_IFINDEX 1

#define LLDPD_AF_UNSPEC 0

#define VLOG_DBG(...)
#define VLOG_INFO(...)
#define VLOG_WARN(...)

#define PEEK_CMP(addr, len) 0
#define PEEK_DISCARD(len)
#define PEEK_UINT16 0
#define PEEK_UINT32 0
#define PEEK_UINT8 0
#define PEEK_SAVE(ptr) (void)0
#define PEEK_BYTES(dst, len)
#define CHECK_TLV_SIZE(size, desc)
#define CHECK_TLV_MAX_SIZE(size, desc)

#define ETH_ADDR_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define ETH_ADDR_ARGS(ea) (ea)[0], (ea)[1], (ea)[2], (ea)[3], (ea)[4], (ea)[5]

struct eth_addr {
    uint8_t ea[ETH_ADDR_LEN];
};

struct lldpd;
struct lldpd_hardware;

struct ovs_list {
    struct ovs_list *next;
    struct ovs_list *prev;
};

struct lldpd_mgmt {
    struct ovs_list m_entries;
    /* Other members omitted */
};

struct lldpd_chassis {
    uint8_t *c_id;
    int c_id_len;
    int c_id_subtype;
    uint16_t c_ttl;
    char *c_name;
    char *c_descr;
    uint16_t c_cap_available;
    uint16_t c_cap_enabled;
    struct ovs_list c_mgmt;
};

struct lldpd_port {
    uint8_t *p_id;
    int p_id_len;
    int p_id_subtype;
    char *p_descr;
    struct {
        int type;
        int vlan_tagging;
        int auto_prov_mode;
        uint16_t mgmt_vlan;
        struct {
            uint8_t system_mac[ETH_ADDR_LEN];
            int conn_type;
            int rsvd;
            uint8_t rsvd2[6];
        } system_id;
    } p_element;
    struct ovs_list p_isid_vlan_maps;
};

struct lldpd_hardware {
    char *h_ifname;
    int h_rx_unrecognized_cnt;
};

struct lldpd_aa_isid_vlan_maps_tlv {
    struct {
        int status;
        uint16_t vlan;
        uint32_t isid;
    } isid_vlan_data;
    struct ovs_list m_entries;
};

static inline void *xzalloc(size_t size) { return calloc(1, size); }
static inline void ovs_list_init(struct ovs_list *list) { list->next = list->prev = list; }
static inline void ovs_list_push_back(struct ovs_list *list, struct ovs_list *elem) {
    elem->next = list;
    elem->prev = list->prev;
    list->prev->next = elem;
    list->prev = elem;
}

static int lldpd_af_from_lldp_proto(uint8_t proto) { return 0; }
static struct lldpd_mgmt *lldpd_alloc_mgmt(int af, uint8_t *addr, uint8_t len, uint32_t iface) { return NULL; }
static void lldpd_chassis_cleanup(struct lldpd_chassis *chassis, bool free_all) {}
static void lldpd_port_cleanup(struct lldpd_port *port, bool free_all) {}