#include <stdint.h>
#include <stdbool.h>

typedef unsigned int uint;

typedef struct ref_stack_t ref_stack_t;
typedef struct i_ctx_t i_ctx_t;
typedef struct ref ref;

enum {
    a_all,
    avm_local
};

extern ref e_stack;
extern void *idmemory;

struct ref {
    union {
        struct {
            ref *refs;
        } value;
    };
};

static int ialloc_ref_array(ref *arr, int a_all, uint size, const char *str);
static int ref_stack_store(const ref_stack_t *pstack, ref *arr, uint size, int a, int b, bool flag, void *idmemory, const char *str);
static uint ref_stack_count(const ref_stack_t *pstack);
static void ialloc_set_space(void *idmemory, int space);
static uint ialloc_space(void *idmemory);
static int errorexec_find(i_ctx_t *i_ctx_p, ref *r);
static void make_null(ref *r);