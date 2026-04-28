#include <stdint.h>

#define BOX_TYPE_DREF 0
#define ENC_BIG_ENDIAN 0
#define _U_

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

extern int hf_mp4_full_box_ver;
extern int hf_mp4_full_box_flags;
extern int hf_mp4_dref_entry_cnt;

extern gint dissect_mp4_box(guint32 box_type, ...);
extern guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);