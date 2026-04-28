#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff_t {
    void *dummy;
} tvbuff_t;

typedef struct packet_info {
    struct {
        const char *COL_INFO;
    } *cinfo;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef int gboolean;
typedef int32_t gint;
typedef uint32_t guint32;
typedef int64_t gint64;

#define NULL ((void*)0)
#define COL_INFO "Info"
#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1

struct CTableColumn {
    uint32_t dummy;
};

struct CPMSetBindingsIn {
    guint32 hcursor;
    guint32 brow;
    guint32 bbindingdesc;
    guint32 dummy;
    guint32 ccolumns;
    struct CTableColumn *acolumns;
};

struct mswsp_ct;
struct message_data {
    struct {
        struct CPMSetBindingsIn bindingsin;
    } content;
};

extern int hf_mswsp_msg;
extern int hf_mswsp_msg_cpmsetbinding_hcursor;
extern int hf_mswsp_msg_cpmsetbinding_cbrow;
extern int hf_mswsp_msg_cpmsetbinding_desc;
extern int hf_mswsp_msg_cpmsetbinding_dummy;
extern int hf_mswsp_msg_cpmsetbinding_ccolumns;
extern int hf_mswsp_msg_cpmsetbinding_acolumns;
extern int ett_mswsp_msg;
extern int ett_mswsp_pad;
extern void* ei_mswsp_msg_cpmsetbinding_ccolumns;

static inline void col_append_str(void *cinfo, const char *col, const char *str) {}
static inline proto_item* proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, int enc) { return NULL; }
static inline proto_tree* proto_item_add_subtree(proto_item *ti, int ett) { return NULL; }
static inline void proto_item_set_text(proto_item *ti, const char *text) {}
static inline proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int len, int ett, proto_item **ti, const char *text) { return NULL; }
static inline uint32_t tvb_get_letohl(tvbuff_t *tvb, int offset) { return 0; }
static inline int tvb_reported_length_remaining(tvbuff_t *tvb, int offset) { return 0; }
static inline int tvb_reported_length(tvbuff_t *tvb) { return 0; }
static inline void expert_add_info(packet_info *pinfo, proto_item *ti, void *ei) {}
static inline void* wmem_alloc(void *scope, size_t size) { return NULL; }
static inline void* get_create_converstation_data(packet_info *pinfo) { return NULL; }
static inline void* find_or_create_message_data(void *ct, packet_info *pinfo, uint32_t msg_type, gboolean in, void *private_data) { return NULL; }
static inline gint parse_padding(tvbuff_t *tvb, gint offset, gint boundary, proto_tree *tree, const char *label_fmt, ...) { return 0; }
static inline gint parse_CTableColumn(tvbuff_t *tvb, gint offset, proto_tree *tree, proto_tree *pad_tree, struct CTableColumn *column, const char *label_fmt, ...) { return 0; }