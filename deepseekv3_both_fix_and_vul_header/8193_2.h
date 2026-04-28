#include <stdint.h>
#include <stdbool.h>

typedef int16_t gint16;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef bool gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

enum rlc_mode {
    RLC_AM,
    RLC_UM,
    RLC_TM,
    RLC_UNKNOWN_MODE
};

struct rlc_li {
    guint16 li;
    guint16 len;
    guint8 ext;
    proto_item *tree;
};

extern gboolean global_rlc_headers_expected;
extern struct expert_field ei_rlc_li_reserved;
extern struct expert_field ei_rlc_li_incorrect_warn;
extern struct expert_field ei_rlc_li_incorrect_mal;
extern struct expert_field ei_rlc_li_too_many;

static proto_item *tree_add_li(enum rlc_mode mode, struct rlc_li *li, guint8 num_li, guint8 li_offs, gboolean li_on_2_bytes, tvbuff_t *tvb, proto_tree *tree);
void expert_add_info(packet_info *pinfo, proto_item *malformed, struct expert_field *expert_field);
void expert_add_info_format(packet_info *pinfo, proto_item *malformed, struct expert_field *expert_field, const char *format, ...);