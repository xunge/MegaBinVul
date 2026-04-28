#include <stdint.h>
#include <stddef.h>

typedef unsigned char u_char;
typedef intptr_t njs_ret_t;
typedef intptr_t nxt_ret_t;

#define NXT_OK 0
#define NXT_ERROR (-1)
#define NXT_REGEX_NOMATCH (-2)

#define nxt_slow_path(cond) (cond)

typedef struct {
    void *pattern;
    void *regex;
} njs_regexp_t;

typedef struct {
    union {
        struct {
            njs_regexp_t *regexp;
        } u;
    } data;
} njs_value_t;

typedef struct {
    void *mem_pool;
    void *regex_context;
    njs_value_t retval;
} njs_vm_t;

typedef struct {
    u_char *start;
    size_t size;
    njs_value_t value;
} njs_string_replace_part_t;

typedef struct {
    int *captures;
    void *substitutions;
    void *function;
    void *match_data;
    int type;
    njs_string_replace_part_t *part;
    struct {
        njs_string_replace_part_t *start;
    } parts;
} njs_string_replace_t;

typedef struct {
    void *regex;
    int global;
} njs_regexp_pattern_t;

typedef struct {
    void *mem_proto;
} njs_array_mem_proto_t;

extern njs_ret_t njs_regexp_match(njs_vm_t *vm, void *regex, const u_char *start, size_t size, void *match_data);
extern int *nxt_regex_captures(void *match_data);
extern njs_ret_t njs_string_replace_substitute(njs_vm_t *vm, njs_string_replace_t *r, int *captures);
extern njs_ret_t njs_string_replace_regexp_join(njs_vm_t *vm, njs_string_replace_t *r);
extern njs_ret_t njs_string_replace_regexp_function(njs_vm_t *vm, njs_value_t *args, njs_string_replace_t *r, int *captures, njs_ret_t ret);
extern njs_string_replace_part_t *nxt_array_add(void *array, njs_array_mem_proto_t *proto, void *mem_pool);
extern void nxt_regex_match_data_free(void *match_data, void *regex_context);
extern void nxt_array_destroy(void *array, njs_array_mem_proto_t *proto, void *mem_pool);
extern void njs_string_copy(njs_value_t *dest, njs_value_t *src);
extern const u_char *nxt_utf8_next(const u_char *p, const u_char *end);
extern void njs_set_invalid(njs_value_t *value);

njs_array_mem_proto_t njs_array_mem_proto;