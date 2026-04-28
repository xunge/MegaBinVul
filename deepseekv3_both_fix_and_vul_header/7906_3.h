#include <stdint.h>
#include <stdlib.h>
#include <time.h>

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int gboolean;

typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct conversation_t conversation_t;
typedef struct wmem_map_t wmem_map_t;

typedef struct nstime_t {
    time_t secs;
    uint32_t nsecs;
} nstime_t;

typedef struct fc_hdr {
    guint8 r_ctl;
    guint32 lun;
    guint32 relative_offset;
} fc_hdr;

typedef struct fcp_conv_data_t {
    wmem_map_t *luns;
} fcp_conv_data_t;

typedef struct itlq_t {
    gboolean first_exchange_frame;
} itlq_t;

typedef struct fcp_request_data_t {
    guint32 request_frame;
    guint32 response_frame;
    nstime_t request_time;
    itlq_t *itlq;
} fcp_request_data_t;

typedef struct fcp_proto_data_t {
    guint32 lun;
} fcp_proto_data_t;

typedef struct frame_data {
    struct {
        gboolean visited;
    } flags;
    nstime_t abs_ts;
} frame_data;

typedef struct packet_info {
    frame_data *fd;
    struct {
        void *src;
        void *dst;
        int ptype;
        int srcport;
        int destport;
        int num;
    };
    struct {
        int COL_PROTOCOL;
        int COL_INFO;
    } *cinfo;
    nstime_t abs_ts;
} packet_info;

enum {
    COL_PROTOCOL,
    COL_INFO
};

extern int proto_fcp;
extern int ett_fcp;
extern int hf_fcp_singlelun;
extern int hf_fcp_request_in;
extern int hf_fcp_response_in;
extern int hf_fcp_time;

extern const char* val_to_str(guint8 val, const void *vs, const char *fmt);
extern const void *fcp_iu_val;
extern const void *fcp_els_iu_val;

#define FC_RCTL_LINK_DATA 0x00
#define FCP_IU_CMD 0x01
#define FCP_IU_RSP 0x02
#define FCP_IU_DATA 0x03
#define FCP_IU_XFER_RDY 0x04
#define FCP_IU_CONFIRM 0x05
#define FCP_IU_UNSOL_CTL 0x06
#define FCP_IU_SOL_CTL 0x07

#define PROTO_ITEM_SET_GENERATED(item) ((void)0)
#define GUINT_TO_POINTER(u) ((void*)(uintptr_t)(u))
#define wmem_file_scope() NULL
#define wmem_new(pool, type) ((type*)malloc(sizeof(type)))
#define wmem_map_new(pool, hash_func, equal_func) NULL
#define wmem_map_lookup(map, key) NULL
#define p_add_proto_data(pool, pinfo, proto, idx, data) ((void)0)
#define p_get_proto_data(pool, pinfo, proto, idx) NULL
#define conversation_add_proto_data(conv, proto, data) ((void)0)
#define conversation_get_proto_data(conv, proto) NULL
#define find_conversation(frame_num, src, dst, ptype, srcport, destport, options) NULL

static inline int tvb_captured_length(const tvbuff_t *tvb) { return 0; }

static inline void col_set_str(void *cinfo, int col, const char *str) {}
static inline void col_add_str(void *cinfo, int col, const char *str) {}
static inline proto_item* proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int len, const char *fmt, ...) { return NULL; }
static inline proto_tree* proto_item_add_subtree(proto_item *ti, int ett) { return NULL; }
static inline proto_item* proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int len, guint32 value) { return NULL; }
static inline proto_item* proto_tree_add_time(proto_item *ti, int hf, tvbuff_t *tvb, int start, int len, nstime_t *time) { return NULL; }

static inline void nstime_delta(nstime_t *delta, const nstime_t *a, const nstime_t *b) {
    delta->secs = a->secs - b->secs;
    delta->nsecs = a->nsecs - b->nsecs;
    if (delta->nsecs < 0) {
        delta->secs--;
        delta->nsecs += 1000000000;
    }
}

extern void dissect_fcp_els(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, fc_hdr *fchdr);
extern void dissect_fcp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, conversation_t *conv, void *itlq, guint32 offset);
extern void dissect_fcp_xfer_rdy(tvbuff_t *tvb, proto_tree *tree);
extern void dissect_fcp_cmnd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *fcp_tree, conversation_t *conv, fc_hdr *fchdr, fcp_conv_data_t *conv_data);
extern void dissect_fcp_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *fcp_tree, conversation_t *conv, fc_hdr *fchdr, fcp_request_data_t *request_data);
extern void call_data_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);