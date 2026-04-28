#include <stdint.h>
#include <stddef.h>

#define PCP_PORT 44321
#define PMPROXY_PORT 44323
#define _U_ __attribute__((unused))

typedef uint32_t guint32;
typedef int32_t gint32;
typedef uint8_t guint8;

typedef struct {
    void *pmid_name_candidates;
    void *pmid_to_name;
    guint32 last_pmns_names_frame;
    guint32 last_processed_pmns_names_frame;
} pcp_conv_info_t;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    struct {
        char *cinfo;
    } *cinfo;
    int srcport;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct conversation conversation_t;
typedef struct expert_field expert_field;

enum {
    COL_PROTOCOL,
    COL_INFO
};

enum {
    ENC_NA,
    ENC_BIG_ENDIAN
};

extern int proto_pcp;
extern int ett_pcp;
extern int hf_pcp_pdu_length;
extern int hf_pcp_pdu_type;
extern int hf_pcp_pdu_pid;
extern expert_field ei_pcp_unimplemented_packet_type;

#define PCP_PDU_CREDS 0
#define PCP_PDU_START_OR_ERROR 1
#define PCP_PDU_PMNS_TRAVERSE 2
#define PCP_PDU_PMNS_NAMES 3
#define PCP_PDU_PMNS_CHILD 4
#define PCP_PDU_PMNS_IDS 5
#define PCP_PDU_PROFILE 6
#define PCP_PDU_FETCH 7
#define PCP_PDU_RESULT 8
#define PCP_PDU_DESC_REQ 9
#define PCP_PDU_DESC 10
#define PCP_PDU_INSTANCE_REQ 11
#define PCP_PDU_INSTANCE 12
#define PCP_PDU_TEXT_REQ 13
#define PCP_PDU_TEXT 14
#define PCP_PDU_USER_AUTH 15

void *g_malloc(size_t size);
void *wmem_array_new(void *scope, size_t elem_size);
void *wmem_map_new(void *scope, unsigned int (*hash_func)(const void*), 
                  int (*equal_func)(const void*, const void*));
void *wmem_file_scope(void);
unsigned int g_direct_hash(const void *v);
int g_direct_equal(const void *v1, const void *v2);
conversation_t *find_or_create_conversation(packet_info *pinfo);
void *conversation_get_proto_data(conversation_t *conv, int proto);
void conversation_add_proto_data(conversation_t *conv, int proto, void *data);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                              int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void col_set_str(void *cinfo, int column, const char *str);
void col_clear(void *cinfo, int column);
void col_append_str(void *cinfo, int column, const char *str);
void expert_add_info(packet_info *pinfo, proto_tree *tree, expert_field *ei);
int tvb_captured_length(tvbuff_t *tvb);