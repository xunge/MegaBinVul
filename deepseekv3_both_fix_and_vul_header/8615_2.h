#include <stdint.h>

typedef int gint;
typedef void* gpointer;
#define GPOINTER_TO_INT(p) ((gint)(intptr_t)(p))

#define CB_STR_ITEM_LEVELS(options) ((options) & 0x0F)
#define CB_STR_COL_INFO (1 << 4)
#define CB_STR_SAVE (1 << 5)

typedef struct _packet_info {
    void* cinfo;
} packet_info;

typedef struct _proto_tree {
} proto_tree;

typedef struct _proto_item {
} proto_item;

typedef struct _dcerpc_info {
    void* call_data;
} dcerpc_info;

typedef struct _tvbuff_t {
} tvbuff_t;

typedef struct _dcerpc_call_value {
    void* private_data;
} dcerpc_call_value;

#define GET_ITEM_PARENT(item) ((proto_item*)0)
#define ENC_UTF_16 0
#define ENC_LITTLE_ENDIAN 0
#define COL_INFO 0
#define _U_ 

void* wmem_packet_scope();
char* tvb_get_string_enc(void* scope, tvbuff_t* tvb, int offset, int length, int encoding);
void col_append_fstr(void* cinfo, int col, const char* format, ...);
void proto_item_append_text(proto_item* item, const char* format, ...);