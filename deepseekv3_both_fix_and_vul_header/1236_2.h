#include <stddef.h>
#include <stdint.h>

typedef int njs_int_t;
typedef uint32_t njs_index_t;

#define NJS_ERROR (-1)
#define NJS_OK (0)
#define NJS_GENERATOR_LOOP 1
#define NJS_GENERATOR_ALL 2
#define njs_vmcode_try_end_t 0

#define njs_slow_path(expr) (expr)

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_parser_node_s njs_parser_node_t;

typedef struct njs_vmcode_finally_s {
    size_t continue_offset;
    size_t break_offset;
} njs_vmcode_finally_t;

typedef struct njs_generator_patch_s njs_generator_patch_t;

typedef struct njs_generator_block_s {
    njs_index_t index;
    void *continuation;
    void *exit;
} njs_generator_block_t;

typedef struct njs_generator_s {
    njs_generator_block_t *block;
    void *context;
} njs_generator_t;

typedef struct njs_generator_try_ctx_s {
    njs_generator_block_t *try_block;
    size_t try_offset;
    njs_index_t exception_index;
    void *try_cont_label;
    void *try_exit_label;
} njs_generator_try_ctx_t;

static void njs_code_set_jump_offset(njs_generator_t *generator, int type, size_t offset);
static void njs_generate_code_finally(njs_generator_t *generator, njs_vmcode_finally_t *finally, 
                                    njs_index_t exception_index, njs_index_t exit_index, void *ptr);
static njs_generator_block_t *njs_generate_find_block(njs_vm_t *vm, njs_generator_block_t *block,
                                                    int type, void *label);
static njs_generator_patch_t *njs_generate_make_continuation_patch(njs_vm_t *vm, njs_generator_block_t *block,
                                                                 void *label, size_t offset);
static size_t njs_code_offset(njs_generator_t *generator, njs_vmcode_finally_t *finally);
static njs_generator_patch_t *njs_generate_make_exit_patch(njs_vm_t *vm, njs_generator_block_t *block,
                                                         void *label, size_t offset);
static njs_int_t njs_generate_index_release(njs_vm_t *vm, njs_generator_t *generator, 
                                          njs_index_t exception_index);
static njs_int_t njs_generator_stack_pop(njs_vm_t *vm, njs_generator_t *generator, 
                                       njs_generator_try_ctx_t *ctx);

static void *no_label;