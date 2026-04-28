#include <stdint.h>

typedef uintptr_t ecma_value_t;
typedef struct ecma_module_t ecma_module_t;
typedef struct ecma_compiled_code_t ecma_compiled_code_t;
typedef struct ecma_object_t ecma_object_t;

struct ecma_context_t {
    struct ecma_context_t *parent_p;
};

#define JERRY_ASSERT(expr) ((void)0)
#define ECMA_MODULE_STATE_PARSED 0
#define ECMA_MODULE_STATE_EVALUATING 1
#define ECMA_MODULE_STATE_EVALUATED 2
#define ECMA_VALUE_EMPTY ((ecma_value_t)0)

struct ecma_module_t {
    int state;
    ecma_object_t* scope_p;
    struct ecma_context_t* context_p;
    ecma_compiled_code_t* compiled_code_p;
};

extern ecma_object_t* ecma_get_global_environment(void);
extern ecma_object_t* ecma_create_decl_lex_env(ecma_object_t*);
extern ecma_value_t vm_run_module(ecma_compiled_code_t*, ecma_object_t*);
extern void jerry_release_value(ecma_value_t);
extern void ecma_bytecode_deref(ecma_compiled_code_t*);
extern int ECMA_IS_VALUE_ERROR(ecma_value_t);

extern struct ecma_context_t* JERRY_CONTEXT_module_top_context_p;
#define JERRY_CONTEXT(x) JERRY_CONTEXT_##x