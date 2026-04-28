#include <stdint.h>
#include <stddef.h>

typedef int32_t njs_int_t;

typedef enum {
    NJS_OK,
    NJS_ERROR,
    NJS_INDEX_NONE
} njs_status_t;

typedef enum {
    NJS_LEVEL_LOCAL,
    NJS_LEVEL_CLOSURE,
    NJS_LEVEL_TEMP
} njs_level_t;

typedef struct njs_value_s {
    uint32_t type;
    union {
        double num;
        void *data;
    } u;
} njs_value_t;

typedef struct njs_function_s njs_function_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_frame_s njs_frame_t;
typedef struct njs_declaration_s njs_declaration_t;
typedef struct njs_function_lambda_s njs_function_lambda_t;

struct njs_frame_s {
    union {
        struct {
            njs_function_t *function;
            njs_value_t **temp;
        } native;
    };
    njs_value_t *arguments;
    njs_value_t **local;
};

struct njs_vm_s {
    njs_frame_t *top_frame;
    njs_frame_t *active_frame;
    njs_value_t **levels[3];
};

struct njs_function_s {
    void *context;
    unsigned global:1;
    unsigned closure_copied:1;
    unsigned args_offset;
    unsigned args_count;
    union {
        njs_function_lambda_t *lambda;
    } u;
};

struct njs_function_lambda_s {
    uint32_t ndeclarations;
    uint32_t self;
    unsigned rest_parameters:1;
    njs_declaration_t *declarations;
    void *start;
};

struct njs_declaration_s {
    uint32_t index;
    njs_value_t *value;
};

#define njs_slow_path(expr) (expr)
#define njs_assert(expr) ((void)0)

njs_int_t njs_function_capture_global_closures(njs_vm_t *vm, njs_function_t *function);
njs_value_t **njs_function_closures(njs_function_t *function);
njs_int_t njs_function_rest_parameters_init(njs_vm_t *vm, void *native);
njs_value_t *njs_scope_value(njs_vm_t *vm, uint32_t index);
void njs_set_function(njs_value_t *value, njs_function_t *function);
int njs_is_valid(njs_value_t *value);
void njs_set_undefined(njs_value_t *value);
njs_function_t *njs_function_value_copy(njs_vm_t *vm, njs_value_t *value);
njs_int_t njs_function_capture_closure(njs_vm_t *vm, njs_function_t *function, njs_function_lambda_t *lambda);
njs_int_t njs_vmcode_interpreter(njs_vm_t *vm, void *start, ...);