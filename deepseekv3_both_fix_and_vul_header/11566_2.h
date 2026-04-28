#include <assert.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNTER_SPEC "%lu"
#define TCPR_802_1Q_H 18
#define TCPR_802_3_H 14
#define ETHER_ADDR_LEN 6
#define ETHERTYPE_VLAN 0x8100
#define TCPR_802_1Q_VIDMASK 0x0FFF

typedef enum {
    TCPR_DIR_C2S,
    TCPR_DIR_S2C
} tcpr_dir_t;

typedef enum {
    ETHERNET
} addr_type_t;

typedef struct tcpr_ethernet_hdr {
    u_char ether_dhost[ETHER_ADDR_LEN];
    u_char ether_shost[ETHER_ADDR_LEN];
    uint16_t ether_type;
} tcpr_ethernet_hdr;

typedef struct tcpr_802_1q_hdr {
    u_char ether_dhost[ETHER_ADDR_LEN];
    u_char ether_shost[ETHER_ADDR_LEN];
    uint16_t vlan_tpi;
    uint16_t vlan_priority_c_vid;
    uint16_t vlan_len;
} tcpr_802_1q_hdr;

typedef struct {
    addr_type_t addr_type;
    u_char ethernet[ETHER_ADDR_LEN];
} ethernet_addr_t;

typedef struct {
    int dlt;
    int l2len;
    uint16_t proto;
    addr_type_t addr_type;
    ethernet_addr_t srcaddr;
    ethernet_addr_t dstaddr;
    int skip_broadcast;
    size_t decoded_extra_size;
    void *decoded_extra;
    struct {
        struct {
            unsigned long packetnum;
        } runtime;
        void *tcpedit;
    } *tcpedit;
    struct {
        int dlt;
    } *decoder;
} tcpeditdlt_t;

typedef struct en10mb_sub_entry {
    u_char target[ETHER_ADDR_LEN];
    u_char rewrite[ETHER_ADDR_LEN];
} en10mb_sub_entry_t;

typedef struct {
    int mac_mask;
    int vlan;
    int vlan_tag;
    int vlan_pri;
    int vlan_cfi;
    u_char intf1_smac[ETHER_ADDR_LEN];
    u_char intf1_dmac[ETHER_ADDR_LEN];
    u_char intf2_smac[ETHER_ADDR_LEN];
    u_char intf2_dmac[ETHER_ADDR_LEN];
    struct {
        int count;
        en10mb_sub_entry_t *entries;
    } subs;
    struct {
        int set;
        int keep;
        u_char mask[ETHER_ADDR_LEN];
    } random;
} en10mb_config_t;

typedef struct {
    int vlan;
    uint16_t vlan_tag;
    uint16_t vlan_pri;
    uint16_t vlan_cfi;
} en10mb_extra_t;

typedef struct {
    size_t config_size;
    en10mb_config_t *config;
} tcpeditdlt_plugin_t;

#define TCPEDIT_ERROR -1
#define TCPEDIT_VLAN_OFF 0
#define TCPEDIT_VLAN_ADD 1
#define TCPEDIT_VLAN_DEL 2
#define TCPEDIT_MAC_MASK_SMAC1 0x01
#define TCPEDIT_MAC_MASK_DMAC1 0x02
#define TCPEDIT_MAC_MASK_SMAC2 0x04
#define TCPEDIT_MAC_MASK_DMAC2 0x08

#define MAC_MASK_APPLY(byte, mask, unicast) ((byte) & (mask)) | (unicast ? (rand() & ~(mask)) : (rand() & ~(mask | 0x01)))

extern int dlt_value;
extern void *tcpedit_dlt_getplugin(tcpeditdlt_t *ctx, int dlt);
extern void tcpedit_seterr(void *tcpedit, const char *format, ...);
extern int is_unicast_ethernet(tcpeditdlt_t *ctx, u_char *addr);