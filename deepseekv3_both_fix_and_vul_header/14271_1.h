#include <stdlib.h>
#include <stdint.h>

typedef uint64_t ut64;

typedef struct RzBinDwarfAttrValue RzBinDwarfAttrValue;

typedef struct {
    ut64 abbrev_code;
    RzBinDwarfAttrValue *attr_values;
    ut64 capacity;
    ut64 count;
} RzBinDwarfDie;

struct RzBinDwarfAttrValue {
    // Add actual members here if needed
};