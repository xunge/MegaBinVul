#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef intptr_t njs_ret_t;
typedef uintptr_t nxt_uint_t;
typedef intptr_t njs_index_t;

typedef unsigned char u_char;

typedef struct {
    u_char *start;
    size_t size;
} njs_string_part_t;

typedef struct {
    u_char *start;
    size_t size;
    size_t length;
} njs_string_prop_t;

typedef struct njs_value_s {
    int type;
} njs_value_t;

typedef struct {
    union {
        struct {
            njs_ret_t (*function)(void);
        } cont;
    } u;
    njs_value_t retval;
    njs_value_t *function;
    njs_string_part_t part[1];
    int utf8;
    int empty;
} njs_string_replace_t;

typedef struct {
    void *mem_pool;
} njs_vm_t;

#define NXT_OK 0
#define NXT_ERROR (-1)
#define nxt_slow_path(cond) (cond)

extern njs_ret_t njs_string_replace_regexp_continuation(void);
extern njs_ret_t njs_function_apply(njs_vm_t *vm, njs_value_t *function, njs_value_t *args, nxt_uint_t nargs, njs_index_t retval);
extern size_t njs_string_calc_length(int utf8, u_char *start, size_t size);
extern njs_ret_t njs_string_new(njs_vm_t *vm, njs_value_t *value, u_char *start, size_t size, size_t length);
extern void njs_set_invalid(njs_value_t *value);
extern void njs_value_number_set(njs_value_t *value, int num);
extern void* nxt_mp_alloc(void *pool, size_t size);
extern void njs_string_prop(njs_string_prop_t *prop, njs_value_t *value);

extern njs_value_t njs_value_undefined;