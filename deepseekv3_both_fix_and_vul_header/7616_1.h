#include <stdint.h>

#define R_API
typedef uint8_t ut8;
typedef uint64_t ut64;

typedef struct r_bin_java_obj_t RBinJavaObj;

typedef enum {
    R_BIN_JAVA_ATTR_TYPE_CONST_VALUE_ATTR
} RBinJavaAttrType;

typedef struct {
    uint16_t constantvalue_idx;
} RBinJavaConstantValueAttr;

typedef struct r_bin_java_attr_info_t {
    RBinJavaAttrType type;
    union {
        RBinJavaConstantValueAttr constant_value_attr;
    } info;
    ut64 size;
} RBinJavaAttrInfo;

#define R_BIN_JAVA_USHORT(buf, offset) (*(uint16_t*)((buf) + (offset)))

RBinJavaAttrInfo *r_bin_java_default_attr_new(RBinJavaObj *bin, ut8 *buffer, ut64 sz, ut64 buf_offset);