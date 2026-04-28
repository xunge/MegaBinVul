#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long ut64;

typedef struct RBinDwarfDie RBinDwarfDie;
typedef struct RBinDwarfAttrValue RBinDwarfAttrValue;
typedef struct RAnal RAnal;

struct RAnalBaseType {
    char *name;
    ut64 size;
    int kind;
};

enum {
    DW_AT_name,
    DW_AT_byte_size,
    DW_AT_bit_size,
    DW_AT_encoding
};

enum {
    R_ANAL_BASE_TYPE_KIND_ATOMIC
};

struct RBinDwarfAttrValue {
    int attr_name;
    union {
        char *content;
        ut64 data;
    } string;
    ut64 data;
};

struct RBinDwarfDie {
    RBinDwarfAttrValue *attr_values;
    size_t count;
    ut64 offset;
};

char *create_type_name_from_offset(ut64 offset);
struct RAnalBaseType *r_anal_new_base_type(int kind);
void r_anal_save_base_type(const RAnal *anal, struct RAnalBaseType *base_type);
void r_anal_free_base_type(struct RAnalBaseType *base_type);
void r_return_if_fail(const void *p);

#define RAnalBaseType struct RAnalBaseType