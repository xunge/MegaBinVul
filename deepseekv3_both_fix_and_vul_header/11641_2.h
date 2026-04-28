#include <stdbool.h>
#include <stddef.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct os_ptr_s {
    struct {
        bool boolval;
    } value;
    struct os_ptr_s *prev;
} *os_ptr;
extern os_ptr osp;

int do_execstack(i_ctx_t *i_ctx_p, bool boolval, ...);