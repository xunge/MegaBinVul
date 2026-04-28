#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef int gboolean;

typedef struct address {
    int type;
    int len;
    const void *data;
} address;

typedef struct {
    int visited;
} fd_options_t;

typedef struct {
    fd_options_t flags;
    int num;
} frame_data;

typedef struct {
    frame_data *fd;
} pinfo_t;

typedef struct {
    pinfo_t *pinfo;
} asn1_ctx_t;

typedef struct {
    guint32 no_ddi_entries;
    guint32 edch_ddi[32];
    guint32 edch_macd_pdu_size[32];
    guint32 lchId[32];
    address crnc_address;
    guint16 crnc_port;
} nbap_edch_channel_info_t;

typedef struct {
    gboolean dch_crc_present;
} nbap_msg_info_for_fp_t;

typedef struct {
    guint32 no_ddi_entries;
    guint32 edch_ddi[32];
    guint32 edch_macd_pdu_size[32];
    guint32 edch_lchId[32];
    gboolean dch_crc_present;
    guint32 edch_type;
    guint32 num_dch_in_flow;
    guint32 dchs_in_flow_list[32];
} umts_fp_conversation_info_t;

typedef struct {} tvbuff_t;
typedef struct {} proto_tree;
typedef struct {} conversation_t;

#define AT_NONE 0
#define PT_UDP 0
#define NO_ADDR_B 0
#define _U_

extern int e_dch_macdflow_id;
extern int e_dch_ddi_value;
extern int proto_fp;
extern nbap_edch_channel_info_t nbap_edch_channel_info[];
extern nbap_msg_info_for_fp_t g_nbap_msg_info_for_fp;
extern int ett_nbap_E_DCH_MACdFlow_Specific_InfoItem;
extern void *E_DCH_MACdFlow_Specific_InfoItem_sequence;

void SET_ADDRESS(address *addr, int type, int len, const void *data);
conversation_t *find_conversation(int num, const address *addr1, const address *addr2, int type, guint16 port1, guint16 port2, int flags);
void *conversation_get_proto_data(const conversation_t *conv, int proto);
int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence);