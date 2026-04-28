#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned char byte;
typedef unsigned long ulong;

typedef struct ref_stack_s {
    int count;
} ref_stack_t;

typedef struct gs_function_s {
    struct {
        int n;
        int BitsPerSample;
        double *Range;
    } params;
} gs_function_t;

typedef struct gs_sampled_data_enum_s {
    gs_function_t *pfn;
    int *indexes;
    int o_stack_depth;
} gs_sampled_data_enum;

typedef struct gs_function_Sd_params_s {
    int n;
    int BitsPerSample;
    double *Range;
} gs_function_Sd_params_t;

typedef struct i_ctx_s {
    int dummy;
} i_ctx_t;

typedef int os_ptr;

#define O_STACK_PAD 4

extern ref_stack_t o_stack;
extern gs_sampled_data_enum *senum;
extern os_ptr osp;
extern int esp;
extern int estack_storage;
extern int (*esp_finish_proc)(i_ctx_t *);
extern int gs_error_undefinedresult;

static int real_param(os_ptr op, double *value);
static byte *cube_ptr_from_index(gs_function_Sd_params_t *params, int *indexes);
static int increment_cube_indexes(gs_function_Sd_params_t *params, int *indexes);
static int sampled_data_sample(i_ctx_t *i_ctx_p);
static int ref_stack_count(ref_stack_t *stack);
static void push(int n);
static void pop(int n);
static void ifree_object(void *obj, const char *msg);
static void make_null(os_ptr op);
static int bits2bytes(int bits);
static int return_error(int error);