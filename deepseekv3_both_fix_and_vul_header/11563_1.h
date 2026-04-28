#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <stdlib.h>
#include <err.h>

#define TCPR_802_1Q_H 18
#define TCPR_802_3_H 14
#define MAXPACKET 65536
#define ETHERTYPE_VLAN 0x8100
#define TCPR_802_1Q_VIDMASK 0x0FFF
#define TCPEDIT_ERROR -1
#define TCPEDIT_VLAN_OFF 0
#define TCPEDIT_VLAN_ADD 1
#define TCPEDIT_VLAN_DEL 2
#define TCPEDIT_MAC_MASK_SMAC1 0x01
#define TCPEDIT_MAC_MASK_DMAC1 0x02
#define TCPEDIT_MAC_MASK_SMAC2 0x04
#define TCPEDIT_MAC_MASK_DMAC2 0x08
#define COUNTER_SPEC "%d"
#define MAC_MASK_APPLY(byte, mask, unicast) ((byte) & (mask)) | (unicast ? (rand() & ~(mask)) : (rand() & ~(mask)))

typedef enum {
    TCPR_DIR_C2S,
    TCPR_DIR_S2C
} tcpr_dir_t;

typedef enum {
    ETHERNET
} addr_type_t;

typedef struct tcpr_ethernet_hdr {
    uint8_t ether_dhost[ETHER_ADDR_LEN];
    uint8_t ether_shost[ETHER_ADDR_LEN];
    uint16_t ether_type;
} tcpr_ethernet_hdr;

typedef struct tcpr_802_1q_hdr {
    uint8_t vlan_dhost[ETHER_ADDR_LEN];
    uint8_t vlan_shost[ETHER_ADDR_LEN];
    uint16_t vlan_tpi;
    uint16_t vlan_priority_c_vid;
    uint16_t vlan_len;
} tcpr_802_1q_hdr;

typedef struct {
    uint16_t vlan_tag;
    uint8_t vlan_pri;
    uint8_t vlan_cfi;
    uint8_t vlan;
} en10mb_extra_t;

typedef struct en10mb_sub_entry {
    uint8_t target[ETHER_ADDR_LEN];
    uint8_t rewrite[ETHER_ADDR_LEN];
} en10mb_sub_entry_t;

typedef struct {
    int mac_mask;
    int vlan;
    uint16_t vlan_tag;
    uint8_t vlan_pri;
    uint8_t vlan_cfi;
    uint8_t intf1_smac[ETHER_ADDR_LEN];
    uint8_t intf1_dmac[ETHER_ADDR_LEN];
    uint8_t intf2_smac[ETHER_ADDR_LEN];
    uint8_t intf2_dmac[ETHER_ADDR_LEN];
    struct {
        int set;
        int keep;
        uint8_t mask[ETHER_ADDR_LEN];
    } random;
    struct {
        int count;
        en10mb_sub_entry_t *entries;
    } subs;
} en10mb_config_t;

typedef struct {
    int dlt;
    int l2len;
    uint16_t proto;
    addr_type_t addr_type;
    struct {
        uint8_t ethernet[ETHER_ADDR_LEN];
    } srcaddr, dstaddr;
    int skip_broadcast;
    void *decoded_extra;
    size_t decoded_extra_size;
    struct {
        void *tcpedit;
        struct {
            int packetnum;
        } runtime;
    } *tcpedit;
    struct {
        int dlt;
    } *decoder;
} tcpeditdlt_t;

typedef struct {
    void *config;
    size_t config_size;
} tcpeditdlt_plugin_t;

extern int dlt_value;
extern int tcpedit_seterr(void *, const char *, ...);
extern tcpeditdlt_plugin_t *tcpedit_dlt_getplugin(tcpeditdlt_t *, int);
extern int is_unicast_ethernet(tcpeditdlt_t *, const uint8_t *);