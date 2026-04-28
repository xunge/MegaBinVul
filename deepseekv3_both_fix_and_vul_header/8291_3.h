#include <stdint.h>
#include <stdlib.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct eth_phdr {
    int fcs_len;
} eth_phdr;

typedef uint32_t guint32;

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define ENC_ASCII 2
#define ENC_UTF_8 4
#define TRUE 1

#define COL_PROTOCOL 0
#define COL_INFO 1

extern int proto_pktap;
extern int ett_pktap;
extern int hf_pktap_hdrlen;
extern int hf_pktap_rectype;
extern int hf_pktap_dlt;
extern int hf_pktap_ifname;
extern int hf_pktap_flags;
extern int hf_pktap_pfamily;
extern int hf_pktap_llhdrlen;
extern int hf_pktap_lltrlrlen;
extern int hf_pktap_pid;
extern int hf_pktap_cmdname;
extern int hf_pktap_svc_class;
extern int hf_pktap_iftype;
extern int hf_pktap_ifunit;
extern int hf_pktap_epid;
extern int hf_pktap_ecmdname;
extern struct expert_field ei_pktap_hdrlen_too_short;
extern void* wtap_encap_dissector_table;

#define MIN_PKTAP_HDR_LEN 8
#define PKT_REC_PACKET 1
#define WTAP_ENCAP_ETHERNET 1

struct packet_info {
    void* cinfo;
};

void col_set_str(void* cinfo, int column, const char* str);
void col_clear(void* cinfo, int column);
void col_add_fstr(void* cinfo, int column, const char* format, ...);

tvbuff_t* tvb_new_subset_remaining(tvbuff_t* tvb, int len);
guint32 tvb_get_letohl(tvbuff_t* tvb, int offset);
proto_item* proto_tree_add_item(proto_tree* tree, int hf, tvbuff_t* tvb, int offset, int len, int encoding);
proto_tree* proto_item_add_subtree(proto_item* ti, int ett);
void proto_tree_add_expert(proto_tree* tree, packet_info* pinfo, struct expert_field* ef, tvbuff_t* tvb, int offset, int len);
int wtap_pcap_encap_to_wtap_encap(guint32 dlt);
void dissector_try_uint_new(void* table, int encap, tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int b, void* phdr);