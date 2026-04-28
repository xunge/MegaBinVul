#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint8_t guint8;
typedef uint16_t guint16;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

extern gint ett_conf_phconv;
extern gint ett_conf_phlist;
extern gint ett_conf_phflags;
extern gint ett_conf_phmod_flags;
extern gint ett_conf_ph_user_flags;

struct conf_phasor_type_t {
    const char *strptr;
};
extern struct conf_phasor_type_t conf_phasor_type[];

extern int hf_conf_phasor_mod_b15;
extern int hf_conf_phasor_mod_b10;
extern int hf_conf_phasor_mod_b09;
extern int hf_conf_phasor_mod_b08;
extern int hf_conf_phasor_mod_b07;
extern int hf_conf_phasor_mod_b06;
extern int hf_conf_phasor_mod_b05;
extern int hf_conf_phasor_mod_b04;
extern int hf_conf_phasor_mod_b03;
extern int hf_conf_phasor_mod_b02;
extern int hf_conf_phasor_mod_b01;
extern int hf_conf_phasor_type_b03;
extern int hf_conf_phasor_type_b02to00;
extern int hf_conf_phasor_user_data;
extern int hf_conf_phasor_scale_factor;
extern int hf_conf_phasor_angle_offset;

#define ENC_BIG_ENDIAN 0

guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset);
proto_tree* proto_tree_add_subtree_format(proto_tree *parent_tree, tvbuff_t *tvb, gint start, gint length, gint idx, void *null, const char *format, ...);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);