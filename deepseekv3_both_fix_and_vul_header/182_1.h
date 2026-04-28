#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int njs_ret_t;
typedef unsigned int nxt_uint_t;
typedef int njs_index_t;

typedef struct {
    const u_char *start;
    size_t size;
    size_t length;
} njs_string_prop_t;

typedef struct njs_vm_s {
    struct {
        int retval;
    } retval;
} njs_vm_t;

typedef struct {
    /* dummy structure */
} njs_value_t;

typedef unsigned char u_char;

#define nxt_slow_path(cond) (cond)
#define NXT_ERROR (-1)
#define NXT_OK (0)

u_char *njs_string_alloc(njs_vm_t *vm, njs_value_t *retval, size_t size, size_t length);
njs_string_prop_t njs_string_prop(njs_string_prop_t *string, njs_value_t *value);
u_char nxt_upper_case(u_char c);
u_char *nxt_utf8_encode(u_char *p, uint32_t code);
uint32_t nxt_utf8_upper_case(const u_char **start, const u_char *end);