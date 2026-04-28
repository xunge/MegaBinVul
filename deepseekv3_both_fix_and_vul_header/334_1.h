#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_ret_t;
typedef uintptr_t nxt_uint_t;
typedef uintptr_t njs_index_t;

typedef struct {
    const char *start;
    size_t size;
} njs_string_prop_t;

typedef struct {
    int empty;
    int type;
    struct {
        union {
            struct {
                struct {
                    int global;
                } *pattern;
            } *regexp;
        } u;
    } data;
} njs_value_t;

typedef struct {
    njs_value_t retval;
    void *match_data;
    void *regex_context;
    struct {
        const char *start;
    } *part;
    int empty;
} njs_string_replace_t;

typedef struct {
    void *regex_context;
} njs_vm_t;

int njs_is_string(njs_value_t *value);
njs_ret_t njs_string_replace_regexp_join(njs_vm_t *vm, njs_string_replace_t *r);
njs_ret_t njs_string_replace_regexp(njs_vm_t *vm, njs_value_t *args, njs_string_replace_t *r);
void nxt_regex_match_data_free(void *match_data, void *regex_context);
void njs_internal_error(njs_vm_t *vm, const char *message, const char *type_string);
njs_string_replace_t *njs_vm_continuation(njs_vm_t *vm);
void njs_string_replacement_copy(void *part, njs_value_t *retval);
void njs_string_prop(njs_string_prop_t *string, njs_value_t *value);
const char *njs_type_string(int type);

#define NXT_ERROR (-1)