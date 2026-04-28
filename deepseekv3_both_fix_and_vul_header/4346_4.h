#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef unsigned int guint;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define ENC_BIG_ENDIAN 0
#define ENC_NA 0
#define COL_INFO 0

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

struct tvbuff {
    int dummy;
};

struct packet_info {
    struct {
        int dummy;
    } *cinfo;
};

struct proto_tree {
    int dummy;
};

struct proto_item {
    int dummy;
};

struct expert_field {
    int dummy;
};

extern int proto_cbch;
extern int ett_schedule_msg;
extern int ett_schedule_new_msg;
extern int hf_gsm_cbch_sched_type;
extern int hf_gsm_cbch_sched_begin_slot;
extern int hf_gsm_cbch_sched_spare;
extern int hf_gsm_cbch_sched_end_slot;
extern int hf_gsm_cbch_slot;
extern int hf_gsm_cbch_padding;
extern expert_field ei_gsm_cbch_sched_end_slot;

#define DISSECTOR_ASSERT(cond) ((void)0)

static inline guint tvb_reported_length(const tvbuff_t *tvb) { return 0; }
static inline void col_append_str(void *cinfo, int col, const char *str) {}
static inline proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int length, const char *format, ...) { return NULL; }
static inline proto_tree *proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static inline proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, int encoding) { return NULL; }
static inline guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static inline void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert) {}
static inline proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **item, const char *format, ...) { return NULL; }
static inline void proto_tree_add_uint_format_value(proto_tree *tree, int hf, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...) {}
static inline void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset) {}
static inline proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **item, const char *text) { return NULL; }