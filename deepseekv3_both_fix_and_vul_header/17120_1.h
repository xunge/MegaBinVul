#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

extern int hf_mp4_stsz_sample_size;
extern int hf_mp4_stsz_sample_count;
extern int hf_mp4_stsz_entry_size;

#define ENC_BIG_ENDIAN 0
#define _U_ __attribute__((unused))

guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);