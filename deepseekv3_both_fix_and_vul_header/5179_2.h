#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define BER_CLASS_UNI 0
#define BER_UNI_TAG_GeneralizedTime 24
#define ENC_ASCII 0

typedef int gboolean;
typedef signed char gint8;
typedef int gint;
typedef unsigned int guint32;
typedef signed int gint32;
typedef unsigned char guint8;

typedef struct {
    const char *true_string;
    const char *false_string;
} ber_pc_codes_t;

typedef struct {
    void *pinfo;
} asn1_ctx_t;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} proto_tree;

typedef struct {
    int dummy;
} proto_item;

typedef struct {
    int dummy;
} expert_field;

typedef struct {
    int dummy;
} packet_info;

typedef struct {
    int dummy;
} value_string;

extern gboolean decode_unexpected;
extern expert_field ei_ber_expected_generalized_time;
extern expert_field ei_ber_error_length;
extern expert_field ei_ber_invalid_format_generalized_time;
extern const value_string ber_class_codes[];
extern const ber_pc_codes_t ber_pc_codes_short;
extern int ett_ber_unknown;

extern int dissect_ber_identifier(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gint8 *ber_class, gboolean *pc, gint32 *tag);
extern int dissect_ber_length(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 *len, gboolean *indefinite);
extern void dissect_unknown_ber(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree);
extern void tvb_ensure_bytes_exist(tvbuff_t *tvb, int offset, int length);
extern const guint8 *tvb_get_string_enc(void *scope, tvbuff_t *tvb, int offset, int length, int encoding);
extern proto_item *proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length, const char *format, ...);
extern proto_item *proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value);
extern proto_tree *proto_item_add_subtree(proto_item *pi, int tree_type);
extern const char *val_to_str_const(int value, const value_string *vs, const char *default_str);
extern int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
extern void *wmem_packet_scope(void);

static int g_snprintf(char *str, size_t size, const char *format, ...) {
    va_list args;
    int ret;
    va_start(args, format);
    ret = vsnprintf(str, size, format, args);
    va_end(args);
    return ret;
}