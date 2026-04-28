#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;
typedef uintptr_t njs_uint_t;
typedef uintptr_t njs_index_t;

struct njs_function_s;
typedef struct njs_function_s njs_function_t;

typedef struct njs_value_s {
    union {
        struct {
            uint32_t type;
            uint32_t data;
        } u;
        struct {
            njs_function_t *native;
        } function;
    };
} njs_value_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_promise_capability_s njs_promise_capability_t;

typedef struct njs_promise_context_s {
    size_t size;
    njs_value_t* args;
    njs_uint_t nargs;
} njs_promise_context_t;

struct njs_function_s {
    union {
        njs_int_t (*native)(njs_vm_t *vm, njs_value_t *args, njs_uint_t nargs, njs_index_t unused);
    } u;
};

#define NJS_OK 0
#define NJS_ERROR (-1)
#define NJS_PROMISE 0

#define njs_slow_path(cond) (cond)
#define njs_is_object(value) ((value)->u.type == 0)
#define njs_object(value) ((njs_object_t*)(value)->u.data)
#define njs_object_proto_lookup(obj, type, ret_type) ((ret_type*)NULL)
#define njs_argument(args, index) (&args[index])
#define njs_arg(args, nargs, index) (nargs > index ? &args[index] : NULL)
#define njs_set_function(value, func) do { \
    (value)->u.type = 0; \
    (value)->function.native = func; \
} while (0)

njs_function_t* njs_promise_create_function(njs_vm_t* vm, size_t size);
njs_int_t njs_value_species_constructor(njs_vm_t* vm, njs_value_t* object, njs_value_t* default_value, njs_value_t* retval);
njs_promise_capability_t* njs_promise_new_capability(njs_vm_t* vm, njs_value_t* constructor);
njs_int_t njs_promise_perform_then(njs_vm_t* vm, njs_value_t* promise, njs_value_t* fulfilled, njs_value_t* rejected, njs_promise_capability_t* capability);
void njs_type_error(njs_vm_t* vm, const char* msg);

njs_int_t njs_promise_constructor(njs_vm_t* vm, njs_value_t* args, njs_uint_t nargs, njs_index_t unused);