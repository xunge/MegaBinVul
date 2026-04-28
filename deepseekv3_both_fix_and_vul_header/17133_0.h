#include <stdint.h>
#include <stdlib.h>

typedef struct tvbuff {
    unsigned char *data;
    size_t length;
} tvbuff_t;

typedef struct proto_tree {
} proto_tree;

typedef struct address {
    int type;
    int len;
    void *addr;
} address;

typedef struct conversation {
    uint32_t num;
    address src_addr;
    address dst_addr;
    int ptype;
    uint16_t port;
    uint32_t options;
} conversation_t;

typedef struct umts_fp_conversation_info {
    int iface_type;
    int division;
    int channel;
    uint32_t dl_frame_number;
    uint32_t ul_frame_number;
    address crnc_address;
    uint16_t crnc_port;
    int paging_indications;
    int rlc_mode;
    int dch_crc_present;
    struct {
        int num_ul_chans;
        int ul_chan_tf_size[16];
        int ul_chan_num_tbs[16];
        int num_dl_chans;
        int dl_chan_tf_size[16];
        int dl_chan_num_tbs[16];
    } fp_dch_channel_info[16];
    int num_dch_in_flow;
    int dchs_in_flow_list[16];
} umts_fp_conversation_info_t;

typedef struct {
    struct {
        int visited;
    } flags;
} fd_struct;

typedef struct {
    uint32_t num;
    int link_dir;
    fd_struct *fd;
} pinfo_struct;

typedef struct {
    pinfo_struct *pinfo;
} asn1_ctx_t;

typedef struct {
    int dch_crc_present;
} nbap_msg_info_for_fp;

typedef struct {
    int num_ul_chans;
    int ul_chan_tf_size[16];
    int ul_chan_num_tbs[16];
    int num_dl_chans;
    int dl_chan_tf_size[16];
    int dl_chan_num_tbs[16];
    int next_dch;
} nbap_dch_chnl_info_struct;

enum {
    AT_IPv4,
    PT_UDP,
    P2P_DIR_DL,
    IuB_Interface,
    Division_FDD,
    CHANNEL_PCH,
    FP_RLC_MODE_UNKNOWN,
    NO_ADDR_B,
    NO_PORT_B,
    NO_ADDR2,
    NO_PORT2,
    FP_maxNrOfDCHs = 16
};

#define _U_ __attribute__((unused))

int transportLayerAddress_ipv4;
uint16_t BindingID_port;
int num_items;
int paging_indications;
int commontransportchannelid;
nbap_msg_info_for_fp g_nbap_msg_info_for_fp;
nbap_dch_chnl_info_struct nbap_dch_chnl_info[16];
void *wmem_file_scope();
void *fp_handle;
int ett_nbap_PCH_ParametersItem_CTCH_SetupRqstFDD;
int PCH_ParametersItem_CTCH_SetupRqstFDD_sequence;

void clear_address(address *addr);
void set_address(address *addr, int type, int len, void *data);
conversation_t *find_conversation(uint32_t num, address *src_addr, address *dst_addr, int ptype, uint16_t port, uint32_t options, int flags);
conversation_t *conversation_new(uint32_t num, address *src_addr, address *dst_addr, int ptype, uint16_t port, uint32_t options, int flags);
void conversation_set_dissector(conversation_t *conv, void *handle);
void *wmem_new0(void *scope, size_t size);
void copy_address_wmem(void *scope, address *dst, address *src);
void set_umts_fp_conv_data(conversation_t *conv, umts_fp_conversation_info_t *info);
void nbap_debug(const char *fmt, ...);
int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence);

#define wmem_new0(scope, type) ((type *)calloc(1, sizeof(type)))