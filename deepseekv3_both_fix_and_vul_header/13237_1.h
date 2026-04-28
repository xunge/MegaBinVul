#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_lvlhsh_query_s njs_lvlhsh_query_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_object_prop_s njs_object_prop_t;

#define njs_fast_path(expr) (expr)
#define NJS_OK 0
#define NJS_DECLINED -1

struct njs_object_s {
    struct njs_object_s *__proto__;
    void *hash;
    void *shared_hash;
};

struct njs_lvlhsh_query_s {
    void *value;
};

struct njs_value_s {
    int dummy;
};