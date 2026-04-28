#include <stdint.h>

typedef struct ref ref;
typedef struct i_ctx_t i_ctx_t;

struct ref {
    union {
        int intval;
        void *opproc;
    } value;
};

struct i_ctx_t {
    // Context structure definition would go here
    // (actual members are not shown in the original code)
};

extern void *imemory;
extern ref e_stack;

int r_is_estack_mark(const ref *ep);
int r_has_type(const ref *ep, int type);
ref *ref_stack_index(ref *stack, long index);
void op_index_ref(void *imemory, unsigned int opindex, ref *perror_object);

#define t_null 0
#define uint unsigned int

void oparray_cleanup();
void oparray_no_cleanup();
void errorexec_cleanup();