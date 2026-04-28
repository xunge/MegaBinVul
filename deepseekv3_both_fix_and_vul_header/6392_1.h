#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBXSMM_API_INTERN
#define LIBXSMM_HANDLE_ERROR(code, err)
#define LIBXSMM_ASSERT(expr)
#define LIBXSMM_ERR_CSR_INPUT 0
#define LIBXSMM_ERR_CSR_READ_LEN 0
#define LIBXSMM_ERR_CSC_ALLOC_DATA 0
#define LIBXSMM_ERR_CSR_READ_DESC 0
#define LIBXSMM_ERR_CSR_READ_ELEMS 0
#define LIBXSMM_ERR_CSR_LEN 0

typedef struct libxsmm_generated_code {
    int dummy;
} libxsmm_generated_code;