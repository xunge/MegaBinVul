#include <stddef.h>

typedef int njs_int_t;
typedef unsigned char u_char;

typedef struct njs_value_s {
    int dummy;
} njs_value_t;

typedef struct njs_lambda_s {
    int temp;
} njs_lambda_t;

typedef struct njs_function_s {
    union {
        njs_lambda_t *lambda;
    } u;
    int args_offset;
    int args_count;
} njs_function_t;

typedef struct njs_native_frame_s {
    size_t size;
    void *free;
    size_t free_size;
    njs_value_t *arguments;
    njs_value_t *arguments_offset;
    njs_value_t **local;
    njs_value_t **temp;
    u_char *pc;
    njs_function_t *function;
} njs_native_frame_t;

typedef struct njs_frame_s {
    njs_native_frame_t native;
    void *previous_active_frame;
} njs_frame_t;

typedef struct njs_vm_s {
    njs_frame_t *active_frame;
} njs_vm_t;

#define NJS_OK 0
#define NJS_FRAME_SIZE sizeof(njs_native_frame_t)

#define njs_is_valid(v) (1)
#define njs_set_undefined(v) do { } while (0)

size_t njs_function_frame_value_count(njs_native_frame_t *frame);
size_t njs_function_frame_args_count(njs_native_frame_t *frame);
njs_value_t *njs_function_frame_values(njs_native_frame_t *frame, njs_value_t **end);