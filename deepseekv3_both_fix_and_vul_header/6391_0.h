#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    void* generated_code;
    size_t buffer_size;
    size_t code_size;
    int code_type;
    int last_error;
    size_t sf_size;
} libxsmm_generated_code;

typedef struct {
    int m;
    int n;
} libxsmm_gemm_descriptor;

#define LIBXSMM_API
#define LIBXSMM_HANDLE_ERROR_VERBOSE(generated_code, error) 