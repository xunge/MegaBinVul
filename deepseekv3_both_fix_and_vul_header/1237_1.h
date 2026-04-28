#include <stddef.h>
#include <stdint.h>

typedef int njs_int_t;
typedef uint32_t njs_index_t;

typedef struct {
    const char *start;
    size_t length;
} njs_str_t;

typedef struct njs_vm_t njs_vm_t;
typedef struct njs_parser_node_t njs_parser_node_t;

typedef struct njs_generator_block_t {
    njs_index_t index;
    void *continuation;
    void *exit;
} njs_generator_block_t;

typedef struct njs_generator_t {
    njs_generator_block_t *block;
    void *context;
} njs_generator_t;

typedef struct njs_generator_try_ctx_t {
    njs_generator_block_t *try_block;
    njs_generator_block_t *catch_block;
    njs_index_t exception_index;
    njs_str_t try_cont_label;
    njs_str_t catch_cont_label;
    njs_str_t try_exit_label;
    njs_str_t catch_exit_label;
} njs_generator_try_ctx_t;

typedef struct njs_vmcode_finally_t {
    uint32_t continue_offset;
    uint32_t break_offset;
} njs_vmcode_finally_t;

typedef struct njs_generator_patch_t njs_generator_patch_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define NJS_GENERATOR_LOOP 0x01
#define NJS_GENERATOR_ALL 0x02
#define NJS_GENERATOR_TRY 0x04

#define njs_slow_path(expr) (expr)

static const njs_str_t no_label = { NULL, 0 };

njs_int_t njs_generate_code_finally(njs_generator_t *generator, njs_vmcode_finally_t *finally, 
                                   njs_index_t exception_index, njs_index_t exit_index, 
                                   njs_parser_node_t *node);
const njs_str_t *njs_generate_jump_destination(njs_vm_t *vm, njs_generator_block_t *block,
                                             const char *desc, int type, 
                                             njs_str_t *try_label, njs_str_t *catch_label);
njs_generator_block_t *njs_generate_find_block(njs_vm_t *vm, njs_generator_block_t *block,
                                             int type, const njs_str_t *label);
njs_generator_patch_t *njs_generate_make_continuation_patch(njs_vm_t *vm, njs_generator_block_t *block,
                                                          const njs_str_t *label, size_t offset);
size_t njs_code_offset(njs_generator_t *generator, void *code);
njs_generator_patch_t *njs_generate_make_exit_patch(njs_vm_t *vm, njs_generator_block_t *block,
                                                  const njs_str_t *label, size_t offset);
njs_int_t njs_generate_index_release(njs_vm_t *vm, njs_generator_t *generator, njs_index_t index);
njs_int_t njs_generator_stack_pop(njs_vm_t *vm, njs_generator_t *generator, void *ctx);