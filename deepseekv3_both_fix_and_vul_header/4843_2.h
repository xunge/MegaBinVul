#include <string.h>
#include <stdint.h>

#define MAX_APN_LENGTH 256

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef unsigned int guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree; 
typedef struct proto_item proto_item;

extern int hf_gtp_apn;

void tvb_memcpy(tvbuff_t *tvb, void *dst, int offset, int length);
void proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *str);
void proto_item_append_text(proto_item *item, const char *format, ...);