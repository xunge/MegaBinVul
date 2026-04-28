#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;

typedef struct {
    const char *content;
} RBinDwarfString;

typedef struct {
    int attr_name;
    union {
        RBinDwarfString string;
        int constant;
    };
} RBinDwarfAttrValue;

typedef struct {
    ut64 offset;
    RBinDwarfAttrValue *attr_values;
    size_t count;
} RBinDwarfDie;

typedef struct {
    char *name;
    int val;
} RAnalEnumCase;

#define DW_AT_name 1
#define DW_AT_const_value 2

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)