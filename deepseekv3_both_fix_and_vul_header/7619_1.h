#include <stdint.h>
#include <stdlib.h>

#define R_API
typedef uint8_t ut8;
typedef uint32_t ut32; 
typedef uint64_t ut64;

#define R_BIN_JAVA_USHORT(buffer, offset) (*(uint16_t*)(buffer + offset))
#define R_BIN_JAVA_ATTR_TYPE_BOOTSTRAP_METHODS_ATTR 1

typedef struct r_list_t {
    void *head;
    void (*free)(void*);
} RList;

typedef struct r_bin_java_bootstrap_method_t {
    ut64 size;
} RBinJavaBootStrapMethod;

typedef struct r_bin_java_obj_t {
    struct {
        void *cur;
    } *b;
} RBinJavaObj;

typedef struct r_bin_java_attr_info_t {
    int type;
    ut64 size;
    union {
        struct {
            ut32 num_bootstrap_methods;
            RList *bootstrap_methods;
        } bootstrap_methods_attr;
    } info;
} RBinJavaAttrInfo;

RList* r_list_newf(void (*f)(void*));
void r_list_append(RList *list, void *data);
void r_bin_java_bootstrap_method_free(void *ptr);
RBinJavaAttrInfo* r_bin_java_default_attr_new(RBinJavaObj *bin, ut8 *buffer, ut64 sz, ut64 buf_offset);
RBinJavaBootStrapMethod* r_bin_java_bootstrap_method_new(ut8 *buffer, ut64 sz, ut64 buf_offset);