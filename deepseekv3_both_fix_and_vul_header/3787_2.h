#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;

typedef struct RBinDwarfDie RBinDwarfDie;
typedef struct RBinDwarfAttrValue RBinDwarfAttrValue;
typedef struct RAnalEnumCase RAnalEnumCase;

struct RAnalEnumCase {
    char *name;
    int val;
};

struct RBinDwarfAttrValue {
    int attr_name;
    union {
        char *content;
        int sdata;
    } string;
    int constant;
};

struct RBinDwarfDie {
    ut64 offset;
    size_t count;
    RBinDwarfAttrValue *attr_values;
};

#define DW_AT_name 1
#define DW_AT_const_value 2

static char *create_type_name_from_offset(ut64 offset) {
    return NULL;
}

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)