#include <setjmp.h>
#include <stddef.h>

struct jpeg_error_mgr {
    int dummy;
};

struct jpeg_common_struct {
    struct jpeg_error_mgr* err;
};

typedef struct jpeg_common_struct *j_common_ptr;

typedef struct my_error_mgr *my_error_ptr;
struct my_error_mgr {
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};