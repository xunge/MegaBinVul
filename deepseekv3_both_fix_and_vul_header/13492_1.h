#include <stdint.h>
#include <stddef.h>

typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _tvbuff tvbuff_t;
typedef struct _expert_field expert_field;

extern int hf_string;
extern expert_field ei_gdsdb_invalid_length;

#define ENC_ASCII 0
#define ENC_BIG_ENDIAN 0

int dword_align(int value);
uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset);
void proto_item_set_len(proto_item *item, int length);
void expert_add_info_format(void *pinfo, proto_item *item, expert_field *expert, const char *format, ...);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);