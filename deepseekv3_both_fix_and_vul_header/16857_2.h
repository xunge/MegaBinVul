#include <stddef.h>
#include <stdbool.h>

typedef int ecma_value_t;

#define ECMA_VALUE_EMPTY 0
#define ECMA_MODULE_STATE_EVALUATED 0
#define ECMA_BUILTIN_ID_OBJECT_PROTOTYPE 0
#define ECMA_OBJECT_TYPE_GENERAL 0
#define LIT_MAGIC_STRING_ASTERIX_CHAR 0

#define JERRY_ASSERT(expr) ((void)0)

typedef struct ecma_module_t ecma_module_t;
typedef struct ecma_module_resolve_stack_t ecma_module_resolve_stack_t;
typedef struct ecma_module_context_t ecma_module_context_t;
typedef struct ecma_module_node_t ecma_module_node_t;
typedef struct ecma_module_names_t ecma_module_names_t;
typedef struct ecma_module_resolve_set_t ecma_module_resolve_set_t;

struct ecma_module_t {
    void* namespace_object_p;
    int state;
    ecma_module_context_t* context_p;
};

struct ecma_module_resolve_stack_t {
    ecma_module_t* module_p;
    ecma_module_resolve_stack_t* next_p;
};

struct ecma_module_context_t {
    ecma_module_node_t* local_exports_p;
    ecma_module_node_t* indirect_exports_p;
    ecma_module_node_t* star_exports_p;
};

struct ecma_module_node_t {
    ecma_module_names_t* module_names_p;
    ecma_module_t* module_request_p;
    ecma_module_node_t* next_p;
};

struct ecma_module_names_t {
    void* imex_name_p;
    ecma_module_names_t* next_p;
};

static ecma_value_t ecma_create_object(void*, size_t, int);
static void* ecma_builtin_get(int);
static ecma_value_t ecma_module_namespace_object_add_export_if_needed(ecma_module_t*, void*);
static void ecma_module_resolve_stack_push(ecma_module_resolve_stack_t**, ecma_module_t*, void*);
static void ecma_module_resolve_stack_pop(ecma_module_resolve_stack_t**);
static bool ecma_module_resolve_set_insert(ecma_module_resolve_set_t**, ecma_module_t*, void*);
static void ecma_module_resolve_set_cleanup(ecma_module_resolve_set_t*);
static void* ecma_get_magic_string(int);
static bool ecma_is_value_empty(ecma_value_t);