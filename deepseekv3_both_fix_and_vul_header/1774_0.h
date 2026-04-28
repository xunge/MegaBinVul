#include <stdlib.h>
#include <errno.h>

struct btf_dump {
    void *type_states;
    const char **cached_names;
    int last_id;
    void *emit_queue;
    void *decl_stack;
    void *type_names;
    void *ident_names;
};

#define IS_ERR_OR_NULL(ptr) ((ptr) == NULL || (ptr) == (void *)-ENOMEM)

void hashmap__free(void *map);