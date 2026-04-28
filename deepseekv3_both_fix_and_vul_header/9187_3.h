#include <stdint.h>
#include <stddef.h>

typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;
typedef size_t gsize;
typedef int gboolean;
typedef char gchar;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;

extern int hf_gsm_a_unused;
extern int hf_gsm_a_odd_even_ind;
extern int hf_gsm_a_mobile_identity_type;
extern int hf_gsm_a_id_dig_1;
extern int hf_gsm_a_imeisv;
extern int hf_gsm_a_filler;
extern int hf_gsm_a_identity_digit1;
extern int hf_gsm_a_imei;
extern int hf_gsm_a_tmsi;
extern int hf_gsm_a_spare_bits;
extern int hf_gsm_a_mbs_ses_id_ind;
extern int hf_gsm_a_tmgi_mcc_mnc_ind;
extern int hf_gsm_a_mbs_service_id;
extern int hf_gsm_a_mbs_session_id;

extern struct expert_field ei_gsm_a_format_not_supported;
extern struct expert_field ei_gsm_a_mobile_identity_type;
extern struct expert_field ei_gsm_a_extraneous_data;

typedef struct {
    const char *out;
} value_string;
extern const value_string Dgt1_9_bcd;

typedef struct _sccp_assoc_t {
    gchar *calling_party;
} sccp_assoc_t;
extern sccp_assoc_t *sccp_assoc;

#define ENC_BIG_ENDIAN 0
#define ENC_NA 0
#define E212_NONE 0
#define TRUE 1
#define FALSE 0

guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, guint32 offset);
const gchar *tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, guint32 offset, guint len, void *ptr, gboolean skip_first);
const gchar *dissect_e212_imsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint len, gboolean skip_first);
guint32 dissect_e212_mcc_mnc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, int ett, gboolean skip_first);
int g_snprintf(gchar *str, gsize n, const gchar *format, ...);
void *wmem_file_scope(void);
gchar *wmem_strdup_printf(void *allocator, const gchar *format, ...);
void expert_add_info(packet_info *pinfo, proto_tree *tree, struct expert_field *expert);
void expert_add_info_format(packet_info *pinfo, proto_item *ti, struct expert_field *expert, const char *format, ...);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, guint32 value);
void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, guint32 value, const char *format, ...);
void proto_tree_add_string_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, const char *value, const char *format, ...);
void proto_tree_add_bits_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 bit_offset, gint no_of_bits, int encoding);
void EXTRANEOUS_DATA_CHECK(guint len, guint consumed_len, packet_info *pinfo, struct expert_field *expert);