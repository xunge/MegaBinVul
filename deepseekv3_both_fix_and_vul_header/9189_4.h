#include <stdint.h>
#include <stdbool.h>

#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0
#define FALSE false

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef uint32_t guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    proto_item *elem_item;
} ansi_a_shared_data_t;

extern int hf_ansi_a_bdtmf_chars_num_chars;
extern int hf_ansi_a_bdtmf_chars_digits;

extern const char *tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, int offset, int len, const char *digits, bool skip_first);
extern void EXTRANEOUS_DATA_CHECK(guint32 len, guint32 curr_offset);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern void proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *str);
extern void proto_item_append_text(proto_item *item, const char *format, ...);

static const char Dgt_dtmf[] = "0123456789*#ABCD";