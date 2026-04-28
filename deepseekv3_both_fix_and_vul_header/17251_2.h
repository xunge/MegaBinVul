#include <stdint.h>

#define T_SRV 33
#define ENC_BIG_ENDIAN 0

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef unsigned char guchar;
typedef char gchar;
typedef int gboolean;

extern int hf_dns_srv_service;
extern int hf_dns_srv_proto;
extern int hf_dns_srv_name;
extern int hf_dns_rr_name;
extern int hf_dns_rr_type;
extern int hf_dns_rr_class_mdns;
extern int hf_dns_rr_cache_flush;
extern int hf_dns_rr_class;
extern int hf_dns_rr_ttl;
extern int hf_dns_rr_len;

struct expert_field {
    int dummy;
};
extern struct expert_field ei_ttl_negative;

void* wmem_packet_scope(void);
gchar** wmem_strsplit(void* allocator, const guchar* str, const char* delimiter, int max_tokens);
void proto_tree_add_string(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, const char* str);
proto_item* proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding);
uint32_t tvb_get_ntohl(tvbuff_t* tvb, int offset);
void expert_add_info(packet_info* pinfo, proto_item* item, struct expert_field* expert);