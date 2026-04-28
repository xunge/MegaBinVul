#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char ut8;
typedef unsigned long long ut64;
typedef unsigned int ut32;

#define R_API
#define R_BIN_JAVA_USHORT(b,o) (b[o] << 8 | b[o+1])
#define R_NEW0(x) calloc(1, sizeof(x))
#define R_BIN_JAVA_ATTR_TYPE_LOCAL_VARIABLE_TYPE_TABLE_ATTR 1
#define R_BIN_JAVA_GLOBAL_BIN NULL

typedef struct r_list_t {
    void *head;
    void *tail;
    unsigned int length;
    void (*free)(void *);
} RList;

typedef struct r_bin_java_local_variable_type_attribute_t {
    ut64 file_offset;
    ut32 start_pc;
    ut32 length;
    ut32 name_idx;
    ut32 signature_idx;
    ut32 index;
    char *name;
    char *signature;
    ut32 size;
} RBinJavaLocalVariableTypeAttribute;

typedef struct r_bin_java_attr_info_t {
    int type;
    union {
        struct {
            ut32 table_length;
            RList *local_variable_table;
        } local_variable_type_table_attr;
    } info;
    ut64 size;
} RBinJavaAttrInfo;

extern RBinJavaAttrInfo *r_bin_java_default_attr_new(ut8 *buffer, ut64 sz, ut64 buf_offset);
extern void r_bin_java_local_variable_type_table_attr_entry_free(void *);
extern RList *r_list_newf(void (*free)(void *));
extern void r_list_append(RList *list, void *data);
extern char *r_bin_java_get_utf8_from_bin_cp_list(void *global_bin, ut32 idx);
extern void eprintf(const char *format, ...);