#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx {
    struct packet_info *pinfo;
} asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct _address {
    int type;
    int len;
    void *data;
} address;
typedef struct _conversation {
    void *data;
} conversation_t;
typedef struct _umts_fp_conversation_info {
    int iface_type;
    int division;
    int channel;
    int dl_frame_number;
    int ul_frame_number;
    address crnc_address;
    int crnc_port;
    int rlc_mode;
    int com_context_id;
    int reset_frag;
} umts_fp_conversation_info_t;
typedef struct packet_info {
    struct frame_data *fd;
    int link_dir;
} packet_info;
typedef struct frame_data {
    int num;
    struct {
        int visited;
    } flags;
} frame_data;
typedef struct expert_field {
    int dummy;
} expert_field_t;
typedef struct nbap_com_context_id {
    int crnc_context;
} nbap_com_context_id_t;

#define _U_
#define AT_NONE 0
#define AT_IPv4 1
#define PT_UDP 0
#define NO_ADDR_B 0
#define NO_PORT_B 0
#define NO_ADDR2 0
#define NO_PORT2 0
#define P2P_DIR_DL 0
#define IuB_Interface 0
#define Division_FDD 0
#define CHANNEL_EDCH 0
#define FP_RLC_MODE_UNKNOWN 0
#define TRUE 1

static int transportLayerAddress_ipv4;
static int BindingID_port;
static int crcn_context_present;
static int com_context_id;
static int node_b_com_context_id;
static int e_dch_macdflow_id;
static umts_fp_conversation_info_t nbap_edch_channel_info[1];
static void *com_context_map;
static expert_field_t ei_nbap_no_set_comm_context_id;
static void *fp_handle;
static int proto_fp;

#define GINT_TO_POINTER(i) ((void*)(intptr_t)(i))
typedef int gint;

static int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *sequence) { return 0; }
static void set_address(address *addr, int type, int len, void *value) {}
static conversation_t *find_conversation(int num, address *addr1, address *addr2, int type, int port1, int port2, int flags) { return NULL; }
static conversation_t *conversation_new(int num, address *addr1, address *addr2, int type, int port1, int port2, int flags) { return NULL; }
static void conversation_set_dissector(conversation_t *conv, void *handle) {}
static void *conversation_get_proto_data(conversation_t *conv, int proto) { return NULL; }
static void copy_address_wmem(void *scope, address *dst, address *src) {}
static void copy_address(address *dst, address *src) {}
static void expert_add_info(packet_info *pinfo, void *item, expert_field_t *expert) {}
static void *wmem_new0(void *scope, size_t size) { return calloc(1, size); }
static void *wmem_packet_scope(void) { return NULL; }
static void *wmem_file_scope(void) { return NULL; }
static char *address_to_str(void *scope, address *addr) { return "0.0.0.0"; }
static void set_umts_fp_conv_data(conversation_t *conv, umts_fp_conversation_info_t *info) {}
static void nbap_debug(const char *fmt, ...) {}
static void *g_tree_lookup(void *tree, void *key) { return NULL; }

#define ett_nbap_E_DCH_FDD_Information_to_Modify 0
#define E_DCH_FDD_Information_to_Modify_sequence NULL

#define sizeof_umts_fp_conversation_info_t sizeof(struct _umts_fp_conversation_info)

/* Fix for the wmem_new0 call with type name */
#define wmem_new0(scope, type) ((type *)calloc(1, sizeof(type)))