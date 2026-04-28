#include <stdint.h>
#include <string.h>

typedef int njs_int_t;

typedef struct njs_value_s njs_value_t;
typedef struct njs_vm_s njs_vm_t;

typedef struct njs_object_prop_s njs_object_prop_t;

typedef struct {
    union {
        uint32_t magic32;
        struct {
            void *prop_handler;
        } u;
    } data;
} njs_value_data_t;

typedef struct {
    uint32_t magic32;
    int writable;
    int configurable;
    int enumerable;
    njs_int_t (*prop_handler)(njs_vm_t*, njs_object_prop_t*, njs_value_t*, void*, njs_value_data_t*);
} njs_exotic_slots_t;

typedef struct {
    void *key;
    void *value;
} njs_lookup_hash_query_t;

struct njs_object_prop_s {
    njs_value_data_t value;
    void *name;
    int type;
    int writable;
    int configurable;
    int enumerable;
};

typedef struct {
    int query;
    int temp;
    void *key;
    njs_object_prop_t scratch;
    njs_lookup_hash_query_t lhq;
} njs_property_query_t;

#define NJS_DECLINED 0
#define NJS_OK 1
#define NJS_PROPERTY_HANDLER 2
#define NJS_PROPERTY_QUERY_GET 3
#define NJS_PROPERTY_QUERY_SET 4
#define NJS_PROPERTY_QUERY_DELETE 5

#define njs_slow_path(cond) (cond)
#define njs_memzero(ptr, size) memset(ptr, 0, size)