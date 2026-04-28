#include <stdint.h>

typedef int njs_int_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_iterator_args_s njs_iterator_args_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_array_s njs_array_t;

struct njs_value_s {
    int dummy;  // Placeholder for actual value structure
};

struct njs_iterator_args_s {
    njs_array_t *data;
};

struct njs_array_s {
    njs_value_t *start;
};

#define NJS_OK 0