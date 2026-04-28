#include <stdint.h>
#include <stddef.h>

#define PID_EXTENDED 0x8000
#define PID_LIST_END 0x7FFF

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef int gint;
typedef unsigned int guint;

struct proto_tree;
struct proto_item;
struct tvbuff_t;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;

extern int ett_rtps_serialized_data;
extern int ett_rtps_data_member;
extern int hf_rtps_pl_cdr_member_id;
extern int hf_rtps_pl_cdr_member_length;
extern int hf_rtps_pl_cdr_member_id_ext;
extern int hf_rtps_pl_cdr_member_length_ext;
extern int hf_rtps_pl_cdr_member;

static inline guint16 tvb_get_guint16(tvbuff_t *tvb, gint offset, guint encoding) { return 0; }
static inline guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, guint encoding) { return 0; }
static inline proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, gint offset, gint length, int ett, proto_item **ti, const char *format, ...) { return NULL; }
static inline void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint encoding) {}
static inline void proto_item_set_len(proto_item *ti, gint length) {}

#define ALIGN_ZERO(offset, boundary, start) \
    do { \
        if (((offset) - (start)) % (boundary)) \
            (offset) += (boundary) - (((offset) - (start)) % (boundary)); \
    } while (0)