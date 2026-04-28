#include <stdint.h>
#include <time.h>

typedef uint32_t guint32;

typedef struct nstime_t {
    time_t secs;
    int nsecs;
} nstime_t;

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    struct {
        int visited;
        nstime_t abs_ts;
    } *fd;
    int num;
} packet_info;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

typedef struct proto_item {
    // dummy structure
} proto_item;

typedef struct wmem_list_t {
    // dummy structure
} wmem_list_t;

typedef struct wmem_list_frame_t {
    // dummy structure
} wmem_list_frame_t;

typedef struct wmem_allocator_t {
    // dummy structure
} wmem_allocator_t;

typedef struct gryphon_pkt_info {
    uint32_t req_frame_num;
    uint32_t rsp_frame_num;
    uint32_t cmd;
    uint32_t cmd_context;
    uint32_t ioctl_command;
    nstime_t req_time;
} gryphon_pkt_info_t;

typedef struct gryphon_conversation {
    wmem_list_t *request_frame_data;
} gryphon_conversation;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

enum {
    CMD_GET_CONFIG,
    CMD_GET_TIME,
    CMD_CARD_GET_SPEED,
    CMD_CARD_GET_FILTER,
    CMD_CARD_ADD_FILTER,
    CMD_CARD_GET_FILTER_HANDLES,
    CMD_CARD_GET_DEFAULT_FILTER,
    CMD_CARD_GET_FILTER_MODE,
    CMD_CARD_GET_EVNAMES,
    CMD_CARD_GET_SPEEDS,
    CMD_SERVER_REG,
    CMD_BLM_GET_MODE,
    CMD_BLM_GET_DATA,
    CMD_BLM_GET_STATS,
    CMD_LDF_LIST,
    CMD_LDF_DESC,
    CMD_GET_LDF_INFO,
    CMD_GET_NODE_NAMES,
    CMD_GET_NODE_SIGNALS,
    CMD_GET_FRAMES,
    CMD_GET_FRAME_INFO,
    CMD_GET_SIGNAL_INFO,
    CMD_GET_SIGNAL_DETAIL,
    CMD_GET_ENCODING_INFO,
    CMD_GET_SCHEDULES,
    CMD_RESTORE_SESSION,
    CMD_CNVT_GET_VALUES,
    CMD_CNVT_GET_UNITS,
    CMD_CNVT_RESTORE_SESSION,
    CMD_CNVT_GET_NODE_SIGNALS,
    CMD_MSGRESP_ADD,
    CMD_MSGRESP_GET,
    CMD_MSGRESP_GET_HANDLES,
    CMD_PGM_DESC,
    CMD_PGM_LIST,
    CMD_PGM_START,
    CMD_PGM_START2,
    CMD_PGM_STATUS,
    CMD_PGM_OPTIONS,
    CMD_PGM_FILES,
    CMD_SCHED_TX,
    CMD_USDT_GET_STMIN_FC,
    CMD_USDT_GET_BSMAX_FC,
    CMD_USDT_GET_STMIN_OVERRIDE,
    CMD_IOPWR_GETINP,
    CMD_IOPWR_GETLATCH,
    CMD_IOPWR_CLRLATCH,
    CMD_IOPWR_GETPOWER,
    CMD_IOPWR_GETOUT,
    CMD_UTIL_GET_INIT_STRATEGY,
    CMD_CARD_IOCTL
};

extern int proto_gryphon;
extern int hf_gryphon_command;
extern int hf_gryphon_cmd_ioctl_context;
extern int hf_gryphon_cmd_context;
extern int hf_gryphon_reserved;
extern int hf_gryphon_status;
extern int hf_gryphon_response_to;
extern int hf_gryphon_response_time;
extern int hf_gryphon_data;
extern int ett_gryphon_response_data;

wmem_allocator_t* wmem_file_scope();
gryphon_conversation* get_conversation_data(packet_info* pinfo);
void p_add_proto_data(wmem_allocator_t *scope, packet_info *pinfo, int proto, uint32_t key, void *proto_data);
void* p_get_proto_data(wmem_allocator_t *scope, packet_info *pinfo, int proto, uint32_t key);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
uint8_t tvb_get_guint8(tvbuff_t *tvb, int offset);
uint32_t tvb_raw_offset(tvbuff_t *tvb);
wmem_list_frame_t* wmem_list_head(wmem_list_t *list);
void* wmem_list_frame_data(wmem_list_frame_t *frame);
wmem_list_frame_t* wmem_list_frame_next(wmem_list_frame_t *frame);
void* wmem_new0(wmem_allocator_t *allocator, size_t size);
proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, uint32_t value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_item* proto_tree_add_time(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, nstime_t *value_ptr);
void proto_item_set_generated(proto_item *item);
proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **it, const char *format, ...);
void nstime_delta(nstime_t *dst, const nstime_t *a, const nstime_t *b);
const char *plurality(int value, const char *singular, const char *plural);

// Response function declarations
int resp_config(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_time(tvbuff_t *tvb, int offset, proto_tree *ft);
int speed(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_addfilt(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_addfilt(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_filthan(tvbuff_t *tvb, int offset, proto_tree *ft);
int dfiltmode(tvbuff_t *tvb, int offset, proto_tree *ft);
int filtmode(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_events(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_getspeeds(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_register(tvbuff_t *tvb, int offset, proto_tree *ft);
int blm_mode(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_blm_data(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_blm_stat(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_list(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_desc(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_get_ldf_info(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_get_node_names(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_get_node_signals(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_get_frames(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_get_frame_info(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_get_signal_info(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_ldf_get_signal_detail(tvbuff_t *tvb, packet_info* pinfo, int offset, proto_tree *ft);
int resp_ldf_get_encoding_info(tvbuff_t *tvb, packet_info* pinfo, int offset, proto_tree *ft);
int resp_ldf_get_schedules(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_restore_session(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_cnvt_get_values(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_cnvt_get_units(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_addresp(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_addresp(tvbuff_t *tvb, int offset, packet_info* pinfo, proto_tree *ft);
int resp_resphan(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_desc(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_list(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_start(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_status(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_files(tvbuff_t *tvb, int offset, proto_tree *ft);
int resp_sched(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_usdt_stmin_fc(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_usdt_bsmax_fc(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_usdt_get_stmin_override(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_bits_in(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_bits_out(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_init_strat(tvbuff_t *tvb, int offset, proto_tree *ft);
int cmd_ioctl_resp(tvbuff_t *tvb, packet_info* pinfo, int offset, proto_tree *ft, uint32_t ioctl_command);

#define wmem_new0(allocator, type) ((type*)wmem_new0_impl(allocator, sizeof(type)))
void* wmem_new0_impl(wmem_allocator_t *allocator, size_t size);