#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct jas_image_cmpt_s {
    int type_;
    int_fast32_t tlx_;
    int_fast32_t tly_;
    int_fast32_t hstep_;
    int_fast32_t vstep_;
    int_fast32_t width_;
    int_fast32_t height_;
    uint_fast16_t prec_;
    bool sgnd_;
    uint_fast32_t cps_;
    void *stream_;
} jas_image_cmpt_t;

#define JAS_IMAGE_CT_UNKNOWN 0

void *jas_malloc(size_t size);
bool jas_safe_intfast32_add(int_fast32_t x, int_fast32_t y, int_fast32_t *result);
bool jas_safe_size_mul(size_t x, size_t y, size_t *result);
void *jas_stream_memopen(char *buf, size_t bufsize);
void *jas_stream_tmpfile();
int jas_stream_seek(void *stream, long offset, int origin);
int jas_stream_putc(void *stream, int c);
void jas_image_cmpt_destroy(jas_image_cmpt_t *cmpt);