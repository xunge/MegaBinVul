#include <stdlib.h>
#include <string.h>

#define maxNrOfCommonMACFlows 32
#define FP_RLC_MODE_UNKNOWN 0
#define CHANNEL_HSDSCH_COMMON 1
#define Division_FDD 1
#define P2P_DIR_DL 0
#define NO_ADDR_B 0
#define NO_ADDR2 0
#define NO_PORT2 0
#define PT_UDP 0
#define AT_NONE 0

typedef struct address {
    int type;
    int len;
    void *data;
} address;

typedef struct {
    int crnc_port;
    int rlc_mode;
    address crnc_address;
} nbap_common_channel_info_t;

typedef struct umts_fp_conversation_info {
    int channel;
    int division;
    int dl_frame_number;
    int ul_frame_number;
    address crnc_address;
    int crnc_port;
    int common_macdflow_id;
    int hsdsch_entity;
    int num_dch_in_flow;
    int dchs_in_flow_list[32];
} umts_fp_conversation_info_t;

typedef struct {
    int num;
    struct {
        int visited;
    } flags;
} fd_t;

typedef struct {
    fd_t *fd;
    int link_dir;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    int dummy;
} proto_tree;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} conversation_t;

extern nbap_common_channel_info_t nbap_common_channel_info[maxNrOfCommonMACFlows];
extern int common_macdflow_id;
extern int ehs;
extern int fp_handle;
extern int ett_nbap_HSDSCH_Common_System_InformationFDD;
extern int HSDSCH_Common_System_InformationFDD_sequence;

conversation_t *find_conversation(int num, address *addr1, address *addr2, int type, int port1, int port2, int flags);
conversation_t *conversation_new(int num, address *addr1, address *addr2, int type, int port1, int port2, int flags);
void conversation_set_dissector(conversation_t *conv, int handle);
void set_umts_fp_conv_data(conversation_t *conv, umts_fp_conversation_info_t *info);
void set_address(address *addr, int type, int len, const void *data);
void copy_address_wmem(void *scope, address *dst, address *src);
void *wmem_new0(void *scope, size_t size);
void *wmem_file_scope(void);
int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, int sequence);

#define _U_ __attribute__((unused))
#define wmem_new0(scope, type) ((type *)calloc(1, sizeof(type)))
#define wmem_file_scope() NULL