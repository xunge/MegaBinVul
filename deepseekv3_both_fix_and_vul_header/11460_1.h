#include <stddef.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct gs_state_s gs_state;
typedef struct ref_s ref;

struct os_ptr_s {
    ref *value;
};
typedef struct os_ptr_s os_ptr;

extern gs_state *igs;
extern os_ptr osp;

enum { t_save };

#define check_type(a, b) (0)
#define gs_gstate_saved(a) (0)
#define restore_page_device(a, b) (0)
#define push_callout(a, b) (0)
#define gs_grestore(a) (0)
#define zrestore(a) (0)