#include <stdint.h>

typedef uint8_t guint8;
typedef uint16_t guint16;

#define ENC_BIG_ENDIAN 0
#define ENC_ASCII 1
#define ENC_NA 2

extern int hf_packetcable_cccV6_suboption;
extern int hf_packetcable_cccV6_pri_dss;
extern int hf_packetcable_cccV6_sec_dss;
extern int hf_packetcable_cccV6_prov_srv_type;
extern int hf_packetcable_cccV6_prov_srv_fqdn;
extern int hf_packetcable_cccV6_prov_srv_ipv6;
extern int hf_packetcable_cccV6_as_krb_nominal_timeout;
extern int hf_packetcable_cccV6_as_krb_max_timeout;
extern int hf_packetcable_cccV6_as_krb_max_retry_count;
extern int hf_packetcable_cccV6_ap_krb_nominal_timeout;
extern int hf_packetcable_cccV6_ap_krb_max_timeout;
extern int hf_packetcable_cccV6_ap_krb_max_retry_count;
extern int hf_packetcable_cccV6_krb_realm;
extern int hf_packetcable_cccV6_tgt_flag;
extern int hf_packetcable_cccV6_tgt_flag_fetch;
extern int hf_packetcable_cccV6_prov_timer;
extern int hf_packetcable_cccV6_sec_tcm;
extern int hf_packetcable_cccV6_sec_tcm_provisioning_server;
extern int hf_packetcable_cccV6_sec_tcm_call_manager_server;

extern void *ei_dhcpv6_no_suboption_len;
extern void *ei_dhcpv6_bogus_length;
extern void *ei_dhcpv6_invalid_type;
extern void *ei_dhcpv6_invalid_time_value;

extern int ett_dhcpv6_pkt_option;

#define PKT_CCCV6_PRI_DSS 1
#define PKT_CCCV6_SEC_DSS 2
#define PKT_CCCV6_IETF_PROV_SRV 3
#define PKT_CCCV6_IETF_AS_KRB 4
#define PKT_CCCV6_IETF_AP_KRB 5
#define PKT_CCCV6_KRB_REALM 6
#define PKT_CCCV6_TGT_FLAG 7
#define PKT_CCCV6_PROV_TIMER 8
#define PKT_CCCV6_IETF_SEC_TKT 9

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info packet_info;
typedef struct tvbuff tvbuff_t;

void expert_add_info_format(packet_info *pinfo, proto_item *item, void *expert, const char *format, ...);
void expert_add_info(packet_info *pinfo, proto_item *item, void *expert);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
void proto_item_append_text(proto_item *item, const char *format, ...);
void dhcpv6_domain(proto_tree *tree, proto_item *item, packet_info *pinfo, int hfindex, tvbuff_t *tvb, int offset, int length);
const char *plurality(int value, const char *singular, const char *plural);