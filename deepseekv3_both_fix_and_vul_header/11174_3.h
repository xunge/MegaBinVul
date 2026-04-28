#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char ut8;
typedef unsigned short ut16;
typedef unsigned int ut32;
typedef unsigned long long ut64;
typedef signed long long st64;

#define R_API
#define R_BIN_JAVA_USHORT(buf, offset) (*(ut16 *)((buf) + (offset)))
#define R_BIN_JAVA_UINT(buf, offset) (*(ut32 *)((buf) + (offset)))
#define IFDBG if(0)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

typedef struct RBinJavaAllocator {
    struct RBinJavaAttrInfo *(*new_obj)(ut8 *buffer, st64 nsz, st64 buf_offset);
} RBinJavaAllocator;

typedef struct RBinJavaAttrMetas {
    char *name;
    RBinJavaAllocator *allocs;
    int ord;
} RBinJavaAttrMetas;

typedef struct RBinJavaAttrInfo {
    RBinJavaAttrMetas *metas;
} RBinJavaAttrInfo;

typedef struct {
    int attr_idx;
} R_BIN_JAVA_GLOBAL_BIN_TYPE;

extern R_BIN_JAVA_GLOBAL_BIN_TYPE *R_BIN_JAVA_GLOBAL_BIN;
extern RBinJavaAttrMetas *r_bin_java_get_attr_type_by_name(const char *name);
extern char *r_bin_java_get_utf8_from_bin_cp_list(R_BIN_JAVA_GLOBAL_BIN_TYPE *bin, ut16 name_idx);