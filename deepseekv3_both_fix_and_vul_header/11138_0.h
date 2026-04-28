#include <stddef.h>

#define PNG_UINT_31_MAX 0x7fffffffL
#define PNG_UINT_32_MAX 0xffffffffL
#define PNG_SET_USER_LIMITS_SUPPORTED
#define PNG_USER_CHUNK_MALLOC_MAX 0

typedef unsigned long png_uint_32;
typedef size_t png_alloc_size_t;

typedef struct png_struct_def png_struct;
typedef png_struct * png_const_structrp;

struct png_struct_def {
    png_uint_32 chunk_name;
    png_uint_32 width;
    png_uint_32 height;
    int channels;
    int bit_depth;
    int interlaced;
    png_alloc_size_t user_chunk_malloc_max;
};

#define png_IDAT 0x49444154L

void png_debug2(int level, const char *message, unsigned long arg1, unsigned long arg2);
void png_chunk_error(png_const_structrp png_ptr, const char *message);