#include <stddef.h>

typedef struct {
    size_t rank;
    size_t* dims;
} matvar_t;

extern int psnip_safe_size_mul(size_t* result, size_t a, size_t b);