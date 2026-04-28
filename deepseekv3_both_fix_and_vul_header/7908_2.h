#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

typedef struct {
    uint8_t rs_sa;
} ipmi_header_t;

typedef struct {
    unsigned int value;
    const char *strptr;
} value_string;

typedef unsigned int guint;
typedef uint32_t guint32;

#define _U_ __attribute__((unused))
#define ENC_LITTLE_ENDIAN 0

extern const char *val_to_str_const(guint val, const value_string *vs, const char *default_str);
extern ipmi_header_t *ipmi_get_hdr(packet_info *pinfo);
extern void ipmi_set_data(packet_info *pinfo, int idx, int val);
extern void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern guint tvb_get_guint8(tvbuff_t *tvb, int offset);

extern int hf_ipmi_picmg_17_cmd;
extern int hf_ipmi_picmg_17_resid;