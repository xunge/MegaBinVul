#include <stdlib.h>
#include <string.h>

typedef unsigned int guint32;
typedef unsigned short guint16;
typedef unsigned char guint8;
typedef int gboolean;
typedef unsigned int guint;
typedef char gchar;
typedef int gint;

#define _U_
#define FALSE 0
#define TRUE 1
#define DE_EMERGENCY_NUM_LIST 0
#define ENC_BIG_ENDIAN 0

struct expert_field {
    int dummy;
};

extern int hf_gsm_a_dtap_emergency_number_information;
extern int hf_gsm_a_dtap_emerg_num_info_length;
extern int hf_gsm_a_spare_bits;
extern int hf_gsm_a_dtap_serv_cat_b5;
extern int hf_gsm_a_dtap_serv_cat_b4;
extern int hf_gsm_a_dtap_serv_cat_b3;
extern int hf_gsm_a_dtap_serv_cat_b2;
extern int hf_gsm_a_dtap_serv_cat_b1;
extern int hf_gsm_a_dtap_emergency_bcd_num;
extern int ett_gsm_dtap_elem[];
extern struct expert_field ei_gsm_a_dtap_end_mark_unexpected;

extern const char* Dgt_mbcd[];
extern char a_bigbuf[];

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;

guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 offset, guint32 length, guint32 value);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
void proto_tree_add_bits_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 bit_offset, gint no_of_bits, int encoding);
void* tvb_memdup(void *scope, tvbuff_t *tvb, guint32 offset, guint32 length);
void* wmem_packet_scope(void);
void my_dgt_tbcd_unpack(char *buf, guint8 *octets, guint8 len, const char **dgt_mbcd);
proto_item* proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, const char *value, const char *format, ...);
void expert_add_info(packet_info *pinfo, proto_item *item, struct expert_field *ei);
const char* tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, guint32 offset, guint32 length, const char *sep, gboolean skip_trailing_f);