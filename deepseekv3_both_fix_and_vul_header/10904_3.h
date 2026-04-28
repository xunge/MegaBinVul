#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;

typedef struct tvbuff_t {
    // dummy tvbuff_t structure
} tvbuff_t;

typedef struct packet_info {
    struct {
        // dummy cinfo structure
        int dummy;
    } cinfo;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define COL_INFO 0
#define ENC_BIG_ENDIAN 0
#define PROTO_CHECKSUM_VERIFY 0

extern int proto_mac_mgmt_msg_dlmap_decoder;
extern int ett_305;
extern int ett_275_phy;
extern int ett_dlmap_ie;
extern int hf_dlmapc_compr;
extern int hf_dlmapc_ulmap;
extern int hf_dlmapc_rsv;
extern int hf_dlmapc_len;
extern int hf_dlmap_phy_fdur_ms;
extern int hf_dlmap_phy_fdur_per_sec;
extern int hf_dlmap_phy_fnum;
extern int hf_dlmap_dcd;
extern int hf_dlmapc_opid;
extern int hf_dlmapc_secid;
extern int hf_dlmap_ofdma_sym;
extern int hf_dlmapc_count;
extern int hf_padding;
extern int hf_mac_header_compress_dlmap_crc;
extern int hf_mac_header_compress_dlmap_crc_status;
extern void* ei_mac_header_invalid_length;
extern void* ei_mac_header_compress_dlmap_crc;

extern uint32_t INC_CID;

#define BYTE_TO_NIB(x) ((x) << 1)
#define NIB_PADDING(x) ((x) & 1)
#define NIBHI(x,y) ((x) >> 1)
#define NIB_ADDR(x) ((x) >> 1)