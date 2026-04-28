#include <stdint.h>
#include <stdlib.h>

#define _U_
#define AT_NONE 0
#define PT_UDP 1
#define NO_ADDR_B 0
#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))

typedef uint32_t guint32;
typedef int32_t gint;

typedef struct {
    guint32 crnc_context;
} nbap_com_context_id_t;

typedef struct {
    guint32 crnc_port[1];
    guint32 crnc_address;
} nbap_edch_port_info_t;

typedef struct {
    void* crnc_address;
    guint32 crnc_port;
    guint32 no_ddi_entries;
    guint32 edch_ddi[1];
    guint32 edch_macd_pdu_size[1];
    guint32 lchId[1];
} nbap_edch_channel_info_t;

typedef struct {
    guint32 no_ddi_entries;
    guint32 edch_ddi[1];
    guint32 edch_macd_pdu_size[1];
    guint32 edch_lchId[1];
    int dch_crc_present;
    int edch_type;
    guint32 num_dch_in_flow;
    guint32 dchs_in_flow_list[1];
} umts_fp_conversation_info_t;

typedef struct {
    int num;
    struct {
        unsigned visited:1;
    } flags;
} fd_struct;

typedef struct {
    fd_struct* fd;
} pinfo_t;

typedef struct {
    pinfo_t* pinfo;
} asn1_ctx_t;

typedef struct {
    int type;
    int len;
    void* addr;
} address;

typedef void proto_tree;
typedef void tvbuff_t;
typedef void conversation_t;

static int num_items;
static int crcn_context_present;
static guint32 node_b_com_context_id;
static guint32 com_context_id;
static void* com_context_map;
static void* edch_flow_port_map;
static guint32 BindingID_port;
static guint32 e_dch_macdflow_id;
static guint32 transportLayerAddress_ipv4;
static guint32 e_dch_ddi_value;
static umts_fp_conversation_info_t g_nbap_msg_info_for_fp;
static nbap_edch_channel_info_t nbap_edch_channel_info[1];
static int ett_nbap_E_DCH_MACdFlow_Specific_InfoItem_to_Modify;
static int E_DCH_MACdFlow_Specific_InfoItem_to_Modify_sequence;
static int proto_fp;
static int ei_nbap_no_find_comm_context_id;
static int ei_nbap_no_find_port_info;

static void* g_tree_lookup(void* tree, void* key) { return NULL; }
static void nbap_debug(const char* fmt, ...) {}
static void expert_add_info(void* pinfo, void* item, int* expert) {}
static void set_address(address* addr, int type, int len, void* data) {}
static conversation_t* find_conversation(int num, void* addr1, void* addr2, int type, int port1, int port2, int flags) { return NULL; }
static void* conversation_get_proto_data(conversation_t* conv, int proto) { return NULL; }
static int dissect_per_sequence(void* tvb, int offset, void* actx, void* tree, int hf, int ett, int seq) { return 0; }