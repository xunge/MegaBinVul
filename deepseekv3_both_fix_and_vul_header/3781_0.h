#include <stdlib.h>
#include <string.h>

typedef struct RBinDwarfDie RBinDwarfDie;
typedef struct RBinDwarfAttrValue RBinDwarfAttrValue;
typedef int st32;

struct RBinDwarfAttrValue {
    struct {
        char *content;
    } string;
};

struct RBinDwarfDie {
    RBinDwarfAttrValue *attr_values;
    unsigned long offset;
};

#define DW_AT_name 0

static st32 find_attr_idx(const RBinDwarfDie *die, int attr);
static char *create_type_name_from_offset(unsigned long offset);