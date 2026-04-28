#include <stdint.h>
#include <stdlib.h>

typedef struct _packet_info {
    void *cinfo;
} packet_info;

typedef struct _proto_tree {
} proto_tree;

typedef struct _proto_item {
} proto_item;

typedef struct _dcerpc_info {
    void *call_data;
} dcerpc_info;

typedef struct _tvbuff_t {
} tvbuff_t;

typedef struct _dcerpc_call_value {
    void *private_data;
} dcerpc_call_value;

typedef int32_t gint;
typedef uint8_t guint8;

#define GPOINTER_TO_INT(p) ((gint)(intptr_t)(p))
#define CB_STR_ITEM_LEVELS(options) ((options) & 0x0F)
#define CB_STR_COL_INFO 0x10
#define CB_STR_SAVE 0x20
#define COL_INFO 0
#define ENC_ASCII 0
#define _U_ 

static inline guint8* tvb_get_string_enc(void*, tvbuff_t*, int, int, int) { return NULL; }
static inline void* wmem_packet_scope() { return NULL; }
static inline void col_append_fstr(void*, int, const char*, ...) {}
static inline void proto_item_append_text(proto_item*, const char*, ...) {}
static inline proto_item* GET_ITEM_PARENT(proto_item*) { return NULL; }