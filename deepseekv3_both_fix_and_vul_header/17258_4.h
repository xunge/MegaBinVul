#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct value_string value_string;
typedef bool gboolean;
#define FALSE false
#define TRUE true

typedef uint8_t guint8;

extern gboolean have_valid_q931_pi;

void dissect_q931_cause_ie_with_info(tvbuff_t *tvb, int offset, int len, proto_tree *tree, int hf_cause_value, guint8 *cause_value, const value_string *ie_vals, void *info);
void dissect_q931_cause_ie_unsafe(tvbuff_t *tvb, int offset, int len, proto_tree *tree, int hf_cause_value, guint8 *cause_value, const value_string *ie_vals);