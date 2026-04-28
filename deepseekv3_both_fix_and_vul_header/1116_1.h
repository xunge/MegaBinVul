#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct r_list_t RList;

typedef struct r_bin_java_classes_attribute_t {
    ut16 inner_class_info_idx;
    ut16 outer_class_info_idx;
    ut16 inner_name_idx;
    ut16 inner_class_access_flags;
    char *flags_str;
    char *name;
    ut64 file_offset;
    ut32 size;
} RBinJavaClassesAttribute;

typedef struct r_bin_java_attr_info_t {
    int type;
    union {
        struct {
            ut16 number_of_classes;
            RList *classes;
        } inner_classes_attr;
    } info;
    ut64 size;
} RBinJavaAttrInfo;

typedef struct r_bin_java_cp_type_obj_t {
    // define as needed
} RBinJavaCPTypeObj;

typedef struct r_bin_java_obj_t {
    // define as needed
} RBinJavaObj;

#define R_BIN_JAVA_USHORT(buf, offset) ((buf[offset] << 8) | buf[offset + 1])
#define R_BIN_JAVA_ATTR_TYPE_INNER_CLASSES_ATTR 1
#define R_NEW0(type) (type *)calloc(1, sizeof(type))
#define IFDBG if(0)
#define R_BIN_JAVA_GLOBAL_BIN NULL
#define R_API

extern RBinJavaAttrInfo *r_bin_java_default_attr_new(RBinJavaObj *bin, ut8 *buffer, ut64 sz, ut64 buf_offset);
extern void r_bin_java_inner_classes_attr_entry_free(void *entry);
extern RBinJavaCPTypeObj *r_bin_java_get_item_from_bin_cp_list(void *bin, ut16 idx);
extern char *r_bin_java_get_item_name_from_bin_cp_list(void *bin, RBinJavaCPTypeObj *obj);
extern char *retrieve_class_method_access_string(ut16 flags);
extern char *r_str_dup(void *p, const char *str);