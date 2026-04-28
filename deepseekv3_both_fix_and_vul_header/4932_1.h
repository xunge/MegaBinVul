#include <setjmp.h>
#include <stdbool.h>

struct jpeg_common_struct;
struct jpeg_decompress_struct {
    struct jpeg_common_struct *src;
};
typedef struct jpeg_common_struct *j_common_ptr;
typedef struct jpeg_decompress_struct *j_decompress_ptr;

struct str_src_mgr {
    jmp_buf setjmp_buffer;
    bool abort;
};