#include <stdint.h>
#include <stdlib.h>

#define guint32 uint32_t
#define gint int32_t
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))

typedef struct {
    struct {
        struct {
            uint32_t num;
            struct {
                int visited;
            } flags;
        } *fd;
    } *pinfo;
} asn1_ctx_t;

static int ett_nbap_E_DCH_MACdFlow_Specific_InfoItem_to_Modify;
static int E_DCH_MACdFlow_Specific_InfoItem_to_Modify_sequence;

enum {
    AT_NONE = 0,
    PT_UDP = 1,
    NO_ADDR_B = 0
};

static int num_items;
static int crcn_context_present;
static uint32_t node_b_com_context_id;
static void *com_context_map;
static uint32_t com_context_id;
static uint32_t BindingID_port;
static uint32_t transportLayerAddress_ipv4;
static uint32_t e_dch_macdflow_id;
static uint32_t e_dch_ddi_value;

typedef struct {
    uint32_t crnc_context;
} nbap_com_context_id_t;

typedef struct {
    uint32_t crnc_address;
    uint32_t *crnc_port;
} nbap_edch_port_info_t;

typedef struct {
    uint32_t no_ddi_entries;
    uint32_t *edch_ddi;
    uint32_t *edch_macd_pdu_size;
    uint32_t *edch_lchId;
    uint32_t edch_type;
    uint32_t num_dch_in_flow;
    uint32_t *dchs_in_flow_list;
    int dch_crc_present;
} umts_fp_conversation_info_t;

typedef struct {
    uint32_t crnc_address;
    uint32_t crnc_port;
    uint32_t no_ddi_entries;
    uint32_t *edch_ddi;
    uint32_t *edch_macd_pdu_size;
    uint32_t *lchId;
} nbap_edch_channel_info_t;

static nbap_edch_channel_info_t nbap_edch_channel_info[1];
static void *edch_flow_port_map;
static struct {
    int dch_crc_present;
} g_nbap_msg_info_for_fp;
static int proto_fp;

typedef struct {
    int dummy;
} expert_field;
static expert_field ei_nbap_no_find_comm_context_id;
static expert_field ei_nbap_no_find_port_info;

typedef struct {
    int addr_type;
    int addr_len;
    void *addr_data;
} address;

typedef struct {
    int dummy;
} conversation_t;
typedef struct {
    int dummy;
} proto_tree;
typedef struct {
    int dummy;
} tvbuff_t;

#define _U_ __attribute__((unused))
#define SET_ADDRESS(addr, type, len, data) do { \
    (addr)->addr_type = (type); \
    (addr)->addr_len = (len); \
    (addr)->addr_data = (data); \
} while(0)

static int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, 
                              proto_tree *tree, int hf_index, int ett, int seq);
static void nbap_debug(const char *fmt, ...);
static void *g_tree_lookup(void *tree, void *key);
static void expert_add_info(void *pinfo, void *item, expert_field *ef);
static conversation_t *find_conversation(uint32_t num, address *addr1, 
                                       address *addr2, int ptype, 
                                       uint32_t port1, uint32_t port2, 
                                       int flags);
static void *conversation_get_proto_data(conversation_t *conv, int proto);