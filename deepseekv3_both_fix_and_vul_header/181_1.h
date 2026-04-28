#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int njs_ret_t;
typedef unsigned int nxt_uint_t;
typedef int njs_index_t;

typedef struct {
    const unsigned char *start;
    size_t size;
    size_t length;
} njs_string_prop_t;

typedef struct njs_vm_s {
    int retval;
} njs_vm_t;

typedef struct {
} njs_value_t;

#define NXT_OK 0
#define NXT_ERROR -1
#define nxt_slow_path(cond) (cond)

static unsigned char nxt_lower_case(unsigned char c);
static unsigned char *nxt_utf8_encode(unsigned char *p, uint32_t u);
static uint32_t nxt_utf8_lower_case(const unsigned char **start, const unsigned char *end);
static void njs_string_prop(njs_string_prop_t *string, njs_value_t *value);
static unsigned char *njs_string_alloc(njs_vm_t *vm, njs_value_t *retval, size_t size, size_t length);