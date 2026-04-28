#include <stdbool.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct os_ptr_s {
    int dummy;
} os_ptr;
extern os_ptr osp;

int do_execstack(i_ctx_t *i_ctx_p, ...);