#include <stdlib.h>
#include <stdint.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;

typedef struct r_list_t RList;
typedef struct r_bin_java_line_number_attribute_t RBinJavaLineNumberAttribute;
typedef struct r_bin_java_attr_info_t RBinJavaAttrInfo;

#define R_BIN_JAVA_ATTR_TYPE_LINE_NUMBER_TABLE_ATTR 1

struct r_bin_java_line_number_attribute_t {
    ut16 start_pc;
    ut16 line_number;
    ut64 file_offset;
    ut32 size;
};

struct r_bin_java_attr_info_t {
    int type;
    union {
        struct {
            ut16 line_number_table_length;
            RList *line_number_table;
        } line_number_table_attr;
    } info;
    ut64 size;
};

#define R_BIN_JAVA_USHORT(buf, offset) ((buf[offset] << 8) | buf[offset + 1])
#define R_NEW0(type) (type *)calloc(1, sizeof(type))
#define R_API

RList *r_list_newf(void (*f)(void *));
void r_list_append(RList *list, void *data);
RBinJavaAttrInfo *r_bin_java_default_attr_new(ut8 *buffer, ut64 sz, ut64 buf_offset);