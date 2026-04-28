#include <stdint.h>
#include <ctype.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef uint8_t guint8;

static int ett_pvfs_server_config;
static int ett_pvfs_server_config_branch;
static int hf_pvfs_getconfig_response_total_bytes;
static int hf_pvfs_getconfig_response_lines;
static int hf_pvfs_getconfig_response_config_bytes;
static int hf_pvfs_getconfig_response_entry;

typedef struct {
    int dummy;
} expert_field;
static expert_field ei_pvfs_malformed;

typedef struct {
    int dummy;
} tvbuff_t;
typedef struct {
    int dummy;
} proto_tree;
typedef struct {
    int dummy;
} packet_info;

#define ENC_LITTLE_ENDIAN 0

static inline int g_ascii_isalnum(char c) {
    return isalnum((unsigned char)c);
}

static inline proto_tree* proto_tree_add_subtree(proto_tree* parent, tvbuff_t* tvb, int offset, int length, int ett, int* idx, const char* text) {
    return NULL;
}

static inline guint32 tvb_get_letohl(tvbuff_t* tvb, int offset) {
    return 0;
}

static inline void proto_tree_add_item(proto_tree* tree, int hf, tvbuff_t* tvb, int offset, int length, int encoding) {
}

static inline const char* tvb_get_ptr(tvbuff_t* tvb, int offset, int length) {
    return NULL;
}

static inline int tvb_captured_length_remaining(tvbuff_t* tvb, int offset) {
    return 0;
}

static inline void proto_tree_add_string_format(proto_tree* tree, int hf, tvbuff_t* tvb, int offset, int length, const char* str, const char* format, ...) {
}

static inline void proto_tree_add_expert(proto_tree* tree, packet_info* pinfo, expert_field* ef, tvbuff_t* tvb, int offset, int length) {
}