#include <setjmp.h>
#include <stdio.h>

struct jpeg_error_mgr {
    struct hd_jpeg_err_t *err;
};

typedef struct jpeg_error_mgr *j_common_ptr;

typedef struct hd_jpeg_err_t {
    struct {
        void (*format_message)(j_common_ptr, char*);
    } jerr;
    char message[256];
    jmp_buf retbuf;
} hd_jpeg_err_t;