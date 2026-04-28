#include <stdint.h>
#include <string.h>
#include <sys/types.h>

typedef int njs_ret_t;
typedef unsigned int nxt_uint_t;
typedef unsigned int njs_index_t;
typedef unsigned char u_char;

typedef struct {
    const u_char *start;
    size_t size;
    size_t length;
} njs_string_prop_t;

typedef struct {
    size_t start;
    size_t length;
} njs_slice_prop_t;

typedef struct njs_value_s {
    int type;
    union {
        int32_t integer;
        double number;
        void *data;
    } u;
} njs_value_t;

typedef struct {
    njs_value_t retval;
} njs_vm_t;

#define nxt_fast_path(cond) (cond)
#define nxt_slow_path(cond) (cond)
#define NXT_OK 0
#define NXT_ERROR 1

static const njs_value_t njs_value_null = {0};

static void njs_string_slice_prop(njs_string_prop_t *string, njs_slice_prop_t *slice,
                                 njs_value_t *args, nxt_uint_t nargs) {}
static njs_ret_t njs_string_slice(njs_vm_t *vm, njs_value_t *retval,
                                 njs_string_prop_t *string, njs_slice_prop_t *slice) { return 0; }
static u_char *njs_string_alloc(njs_vm_t *vm, njs_value_t *retval, size_t length, int zero) { return NULL; }
static const u_char *njs_string_offset(const u_char *start, const u_char *end, size_t offset) { return NULL; }
static uint32_t nxt_utf8_decode(const u_char **s, const u_char *end) { return 0; }
static void njs_release(njs_vm_t *vm, njs_value_t *retval) {}