#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ut8;
typedef unsigned long long ut64;
typedef unsigned int ut32;
typedef unsigned short ut16;

#define R_API
#define R_BIN_JAVA_ATTR_TYPE_CODE_ATTR 1
#define R_BIN_JAVA_ATTR_TYPE_LOCAL_VARIABLE_TABLE_ATTR 2

typedef struct r_list_t RList;
typedef struct r_bin_java_exception_entry_t RBinJavaExceptionEntry;
typedef struct r_bin_java_attr_info_t RBinJavaAttrInfo;
typedef struct r_bin_java_global_bin_t RBinJavaGlobalBin;
typedef struct r_bin_java_stack_frame_t RBinJavaStackFrame;

struct r_list_t {
    void (*free)(void *);
    // Other list fields would be here
};

struct r_bin_java_exception_entry_t {
    ut64 file_offset;
    ut32 start_pc;
    ut32 end_pc;
    ut32 handler_pc;
    ut32 catch_type;
    ut32 size;
};

struct r_bin_java_stack_frame_t {
    ut64 file_offset;
    // Other frame fields would be here
};

struct r_bin_java_attr_info_t {
    int type;
    union {
        struct {
            ut32 max_stack;
            ut32 max_locals;
            ut32 code_length;
            ut64 code_offset;
            ut8 *code;
            ut32 exception_table_length;
            RList *exception_table;
            ut32 attributes_count;
            RList *attributes;
            RBinJavaStackFrame *implicit_frame;
        } code_attr;
    } info;
    ut64 size;
    ut64 file_offset;
    char *name;
};

struct r_bin_java_global_bin_t {
    RBinJavaAttrInfo *current_code_attr;
};

#define R_BIN_JAVA_USHORT(buf, offset) (*(ut16 *)(buf + offset))
#define R_BIN_JAVA_UINT(buf, offset) (*(ut32 *)(buf + offset))
#define R_NEW0(type) ((type *)calloc(1, sizeof(type)))
#define IFDBG if(0)
#define PFMT64x "llx"

extern RBinJavaAttrInfo *r_bin_java_default_attr_new(ut8 *buffer, ut64 sz, ut64 buf_offset);
extern void r_bin_java_attribute_free(void *);
extern void *r_bin_java_read_next_attr_from_buffer(ut8 *buffer, int size, ut64 buf_offset);
extern RBinJavaStackFrame *r_bin_java_build_stack_frame_from_local_variable_table(RBinJavaGlobalBin *bin, RBinJavaAttrInfo *attr);
extern RBinJavaStackFrame *r_bin_java_default_stack_frame(void);
extern void r_bin_java_print_stack_map_frame_summary(RBinJavaStackFrame *frame);
extern void eprintf(const char *fmt, ...);
extern RList *r_list_newf(void (*free)(void *));
extern void r_list_append(RList *list, void *data);

extern RBinJavaGlobalBin *R_BIN_JAVA_GLOBAL_BIN;