#include <stdint.h>

#define BOX_TYPE_STSD 0x73747364

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

#define ENC_BIG_ENDIAN 0

static int hf_mp4_full_box_ver;
static int hf_mp4_full_box_flags;
static int hf_mp4_stsd_entry_cnt;

typedef int32_t gint;
typedef uint32_t guint;
typedef uint32_t guint32;

static gint dissect_mp4_box(guint32 box_type, ...);

static void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, gint length, int encoding);
static uint32_t tvb_get_ntohl(tvbuff_t *tvb, gint offset);