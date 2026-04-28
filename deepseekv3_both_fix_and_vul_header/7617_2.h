#include <stdint.h>
#include <stdlib.h>

#define R_API
typedef uint8_t ut8;
typedef uint32_t ut32;
typedef uint64_t ut64;

typedef struct r_bin_java_obj_t RBinJavaObj;
typedef struct r_bin_java_attr_info_t RBinJavaAttrInfo;

struct r_bin_java_annotation_t {
    ut64 size;
};
typedef struct r_bin_java_annotation_t RBinJavaAnnotation;

#define R_BIN_JAVA_ATTR_TYPE_RUNTIME_INVISIBLE_ANNOTATION_ATTR 0
#define R_BIN_JAVA_USHORT(buf, offset) 0

struct r_bin_java_attr_info_t {
    int type;
    union {
        struct {
            ut32 num_annotations;
            void *annotations;
        } annotation_array;
        struct {
            ut32 num_annotations;
        } rtv_annotations_attr;
    } info;
    ut64 size;
};

RBinJavaAttrInfo *r_bin_java_default_attr_new(RBinJavaObj *bin, ut8 *buffer, ut64 sz, ut64 buf_offset);
RBinJavaAnnotation *r_bin_java_annotation_new(ut8 *buffer, ut64 sz, ut64 buf_offset);
void r_bin_java_annotation_free(void *p);
void *r_list_newf(void (*free)(void *));
void r_list_append(void *list, void *p);