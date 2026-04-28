#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long ut64;

typedef struct {
    char *content;
} RString;

typedef struct {
    int attr_name;
    union {
        RString string;
        ut64 data;
        ut64 reference;
    };
} RBinDwarfAttrValue;

typedef struct {
    ut64 offset;
    RBinDwarfAttrValue *attr_values;
    size_t count;
} RBinDwarfDie;

typedef struct {
    char *name;
    char *type;
    ut64 offset;
    ut64 size;
} RAnalStructMember;

typedef struct {
    char *buf;
    size_t len;
    size_t size;
} RStrBuf;

void r_strbuf_init(RStrBuf *sb);
char *r_strbuf_drain_nofree(RStrBuf *sb);

void parse_type(const RBinDwarfDie *all_dies, const ut64 all_dies_count, ut64 reference, RStrBuf *strbuf, ut64 *size);
char *create_type_name_from_offset(ut64 offset);

#define DW_AT_name 1
#define DW_AT_type 2
#define DW_AT_data_member_location 3
#define DW_AT_accessibility 4
#define DW_AT_mutable 5
#define DW_AT_data_bit_offset 6
#define DW_AT_byte_size 7
#define DW_AT_bit_size 8
#define DW_AT_containing_type 9

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)