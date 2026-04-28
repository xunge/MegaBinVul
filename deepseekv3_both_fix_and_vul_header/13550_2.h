#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef uint32_t guint;
typedef uint8_t guint8;
typedef unsigned char guchar;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct _GStringPool GStringPool;
typedef struct _col_info_t col_info_t;

extern int hf_msmms_command_prefix1_command_level;
extern int hf_msmms_command_prefix2;
extern int hf_msmms_command_server_file;

#define ENC_LITTLE_ENDIAN 0
#define ENC_UTF_16 0
#define COL_INFO 0

struct packet_info {
    GStringPool *pool;
    col_info_t *cinfo;
};

const char* format_text(GStringPool *pool, const guchar *str, size_t len);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, GStringPool *pool, const guint8 **retval);
void col_append_fstr(col_info_t *cinfo, int column, const char *format, ...);