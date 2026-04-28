#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <net/ethernet.h>

#define COUNTER_SPEC "%d"

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

typedef struct en10mb_sub_entry {
    u_char target[ETHER_ADDR_LEN];
    u_char rewrite[ETHER_ADDR_LEN];
} en10mb_sub_entry_t;

typedef struct {
    en10mb_sub_entry_t *entries;
    int count;
} en10mb_sub_t;

typedef struct {
    u_char mask[ETHER_ADDR_LEN];
    int set;
    int keep;
} en10mb_random_t;

typedef struct en10mb_config {
    u_char intf1_smac[ETHER_ADDR_LEN];
    u_char intf1_dmac[ETHER_ADDR_LEN];
    u_char intf2_smac[ETHER_ADDR_LEN];
    u_char intf2_dmac[ETHER_ADDR_LEN];
    int mac_mask;
    int vlan;
    uint16_t vlan_tag;
    uint8_t vlan_pri;
    uint8_t vlan_cfi;
    en10mb_sub_t subs;
    en10mb_random_t random;
} en10mb_config_t;

typedef struct en10mb_extra {
    int vlan;
    uint16_t vlan_tag;
    uint16_t vlan_pri;
    uint16_t vlan_cfi;
} en10mb_extra_t;

#define TCPR_802_3_H 14
#define TCPR_802_1Q_H 18
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

#define MAC_MASK_APPLY(byte, mask, unicast) ((byte) & (mask)) | (unicast ? (rand() & ~(mask)) : (rand() & ~(mask) | 0x01))

typedef enum {
    ETHERNET,
    OTHER
} addr_type_t;

typedef enum {
    TCPR_DIR_C2S,
    TCPR_DIR_S2C
} tcpr_dir_t;

typedef struct {
    int dlt;
} decoder_t;

typedef struct {
    int packetnum;
} runtime_t;

typedef struct tcpedit_s {
    runtime_t runtime;
} tcpedit_t;

typedef struct {
    union {
        u_char ethernet[ETHER_ADDR_LEN];
    } srcaddr, dstaddr;
    addr_type_t addr_type;
    int skip_broadcast;
    uint16_t proto;
    int l2len;
    void *decoded_extra;
    size_t decoded_extra_size;
    tcpedit_t *tcpedit;
    decoder_t *decoder;
} tcpeditdlt_t;

typedef struct {
    void *config;
    size_t config_size;
} tcpeditdlt_plugin_t;

extern tcpeditdlt_plugin_t *tcpedit_dlt_getplugin(tcpeditdlt_t *ctx, int dlt_value);
extern void tcpedit_seterr(tcpedit_t *tcpedit, const char *format, ...);
extern int is_unicast_ethernet(tcpeditdlt_t *ctx, u_char *addr);
extern void errx(int status, const char *format, ...);

static int dlt_value;