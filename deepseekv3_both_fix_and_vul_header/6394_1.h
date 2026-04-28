#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBXSMM_API_INTERN
#define LIBXSMM_MAX(a, b) ((a) > (b) ? (a) : (b))
#define LIBXSMM_ASSERT(expr) ((void)0)

typedef struct libxsmm_generated_code libxsmm_generated_code;

enum {
    LIBXSMM_ERR_CSR_INPUT,
    LIBXSMM_ERR_CSR_READ_LEN,
    LIBXSMM_ERR_CSC_ALLOC_DATA,
    LIBXSMM_ERR_CSR_READ_DESC,
    LIBXSMM_ERR_CSR_READ_ELEMS,
    LIBXSMM_ERR_CSR_LEN
};

void LIBXSMM_HANDLE_ERROR(libxsmm_generated_code* code, int error);