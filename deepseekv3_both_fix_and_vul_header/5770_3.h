#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef unsigned int guint;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_gsm_a_extension;
extern int hf_gsm_a_dtap_type_of_number;
extern int hf_gsm_a_dtap_numbering_plan_id;
extern int hf_gsm_a_dtap_present_ind;
extern int hf_gsm_a_spare_bits;
extern int hf_gsm_a_dtap_screening_ind;
extern expert_field ei_gsm_a_dtap_end_mark_unexpected;

#define NO_MORE_DATA_CHECK(len)
#define ENC_BIG_ENDIAN 0

void *wmem_packet_scope();
void *tvb_memdup(void *scope, tvbuff_t *tvb, guint32 offset, guint32 len);
guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, guint32 offset, guint32 len, int encoding);
void proto_tree_add_bits_item(proto_tree *tree, int hf, tvbuff_t *tvb, guint32 bit_offset, guint32 no_of_bits, int encoding);
proto_item* proto_tree_add_string(proto_tree *tree, int hf, tvbuff_t *tvb, guint32 offset, guint32 len, const char *str);
proto_item* proto_tree_add_string_format(proto_tree *tree, int hf, tvbuff_t *tvb, guint32 offset, guint32 len, const char *str, const char *format, ...);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);

void my_dgt_tbcd_unpack(char *a_bigbuf, guint8 *poctets, guint32 num_string_len, void *Dgt_mbcd);
const char *tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, guint32 offset, guint32 len, void *unused, gboolean skip_first);

static char a_bigbuf[256];
static void *Dgt_mbcd;