#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct RBinDwarfDie RBinDwarfDie;
typedef struct RBinDwarfAttrValue RBinDwarfAttrValue;
typedef struct RAnalStructMember RAnalStructMember;
typedef struct RStrBuf RStrBuf;
typedef unsigned long long ut64;

enum {
    DW_AT_name,
    DW_AT_type,
    DW_AT_data_member_location,
    DW_AT_accessibility,
    DW_AT_mutable,
    DW_AT_data_bit_offset,
    DW_AT_byte_size,
    DW_AT_bit_size,
    DW_AT_containing_type
};

struct RBinDwarfAttrValue {
    int attr_name;
    union {
        char *content;
        ut64 reference;
        ut64 data;
    } string;
    ut64 reference;
    ut64 data;
};

struct RBinDwarfDie {
    RBinDwarfAttrValue *attr_values;
    size_t count;
    ut64 offset;
};

struct RAnalStructMember {
    char *name;
    char *type;
    ut64 offset;
    ut64 size;
};

struct RStrBuf {
    char *buf;
    size_t len;
    size_t capacity;
};

static void r_strbuf_init(RStrBuf *sb) {
    sb->buf = NULL;
    sb->len = 0;
    sb->capacity = 0;
}

static char *r_strbuf_drain_nofree(RStrBuf *sb) {
    char *result = sb->buf;
    sb->buf = NULL;
    sb->len = 0;
    sb->capacity = 0;
    return result;
}

static void parse_type(const RBinDwarfDie *all_dies, const ut64 all_dies_count, ut64 reference, RStrBuf *strbuf, ut64 *size) {
    *size = 0;
}

static char *create_type_name_from_offset(ut64 offset) {
    return strdup("unknown");
}

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define CHAR_BIT 8