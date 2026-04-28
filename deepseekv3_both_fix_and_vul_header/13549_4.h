#include <stdint.h>
#include <string.h>

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef uint8_t guchar;

#define ENC_LITTLE_ENDIAN 0
#define ENC_UTF_16 0
#define COL_INFO 0

typedef struct tvbuff_t {
    uint8_t* data;
    size_t length;
} tvbuff_t;

typedef struct _proto_tree {
    int dummy;
} proto_tree;

typedef struct _column_info {
    int dummy;
} column_info;

typedef struct _packet_info {
    column_info* cinfo;
    void* pool;
} packet_info;

guint32 tvb_get_letohl(tvbuff_t *tvb, guint offset);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb,
                        guint offset, guint length, int encoding);
void proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb,
                                  guint offset, guint length, int encoding,
                                  void* pool, const guint8** retval);
void col_append_fstr(column_info* cinfo, int column, const char* format, ...);
char* format_text(void* pool, const guchar* buf, size_t len);

extern int hf_msmms_command_prefix1_error;
extern int hf_msmms_command_prefix2;
extern int hf_msmms_command_server_version_length;
extern int hf_msmms_command_tool_version_length;
extern int hf_msmms_command_update_url_length;
extern int hf_msmms_command_password_type_length;
extern int hf_msmms_command_server_version;
extern int hf_msmms_command_tool_version;
extern int hf_msmms_command_update_url;
extern int hf_msmms_command_password_type;