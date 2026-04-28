#include <string.h>

typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned char guchar;

extern int hf_msmms_command_prefix1;
extern int hf_msmms_command_prefix2; 
extern int hf_msmms_command_client_player_info;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct _GStringPool {
    // dummy pool structure
} GStringPool;

struct packet_info {
    GStringPool *pool;
    struct _column_info *cinfo;
};

struct _column_info {
    // dummy column info structure
};

#define ENC_LITTLE_ENDIAN 0
#define ENC_UTF_16 0
#define COL_INFO 0

const char* format_text(GStringPool *pool, const guchar *str, size_t len);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, GStringPool *pool, const guint8 **retval);
void col_append_fstr(struct _column_info *cinfo, int col, const char *format, ...);