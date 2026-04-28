#include <stdint.h>

#define BLOCK_TYPE_SYSDIG_EVENT_V2_LARGE 0
#define BLOCK_TYPE_SYSDIG_EVENT_V2 1
#define SYSDIG_PARAM_SIZE_V2_LARGE 4
#define SYSDIG_PARAM_SIZE_V2 2
#define SYSDIG_PARAM_SIZE 2
#define FT_STRING 1

typedef uint32_t guint32;
typedef uint16_t guint16;

typedef struct wtap_syscall_header {
    uint32_t record_type;
    uint32_t nparams;
} wtap_syscall_header;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

extern int dissect_header_lens_v2_large(tvbuff_t *tvb, wtap_syscall_header* syscall_header, int offset, proto_tree *tree, int encoding);
extern int dissect_header_lens_v2(tvbuff_t *tvb, wtap_syscall_header* syscall_header, int offset, proto_tree *tree, int encoding);
extern int dissect_header_lens_v1(tvbuff_t *tvb, int offset, proto_tree *tree, int encoding, int * const *hf_indexes);
extern const char *format_param_str(tvbuff_t *tvb, int offset, int len);
extern int proto_registrar_get_ftype(int hf_index);
extern void proto_tree_add_string(proto_tree *tree, int hf_index, tvbuff_t *tvb, int offset, int len, const char *str);
extern void proto_tree_add_item(proto_tree *tree, int hf_index, tvbuff_t *tvb, int offset, int len, int encoding);
extern guint32 tvb_get_guint32(tvbuff_t *tvb, int offset, int encoding);
extern guint16 tvb_get_guint16(tvbuff_t *tvb, int offset, int encoding);