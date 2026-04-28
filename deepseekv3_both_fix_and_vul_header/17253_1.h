#include <stdint.h>
#include <stdlib.h>

typedef uint8_t guint8;
typedef int32_t gint;
typedef int gboolean;
typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    int nature_of_address;
    int e164_number_type;
    char *E164_number_str;
    int E164_number_length;
} e164_info_t;

typedef struct {
    char *calling_number;
    char *called_number;
} q931_packet_info;

#define Q931_IE_VL_EXTENSION 0x80
#define ENC_ASCII 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0

#define NONE 0
#define CALLING_PARTY_NUMBER 1
#define CALLED_PARTY_NUMBER 2

extern int hf_q931_numbering_plan;
extern int hf_q931_number_type;
extern int hf_q931_extension_ind;
extern int hf_q931_screening_ind;
extern int hf_q931_presentation_ind;
extern int hf_q931_extension_reason;
extern q931_packet_info *q931_pi;
extern gboolean have_valid_q931_pi;

extern void *wmem_packet_scope(void);
extern char *tvb_format_text(tvbuff_t *tvb, int offset, int len);
extern char *tvb_get_string_enc(void *scope, tvbuff_t *tvb, int offset, int len, int encoding);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int len, int encoding);
extern void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int len, guint32 value);
extern void proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int len, gboolean value);
extern proto_tree *proto_tree_get_parent(proto_tree *tree);
extern void dissect_e164_number(tvbuff_t *tvb, proto_tree *tree, int offset, int len, e164_info_t e164_info);