#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

#define ENC_NA 0

extern int hf_zbee_zcl_pwr_prof_pwr_prof_count;
extern int ett_zbee_zcl_pwr_prof_pwrprofiles[];
extern int ZBEE_ZCL_PWR_PROF_NUM_PWR_PROF_ETT;

guint8 tvb_get_guint8(tvbuff_t *tvb, guint offset);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint offset, gint length, int encoding);
proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, guint offset, gint length, int ett, void* data, const char *format, ...);
void dissect_zcl_power_profile(tvbuff_t *tvb, proto_tree *tree, guint *offset);