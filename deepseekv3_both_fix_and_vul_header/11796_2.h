#include <stddef.h>

typedef struct gs_state_s gs_state;
typedef struct gs_state_s *gs_gstate;
typedef struct i_ctx_s i_ctx_t;
typedef struct os_ptr_s {
    int type;
} *os_ptr;

extern gs_gstate igs;
extern os_ptr osp;

enum { t_save };

static gs_gstate gs_gstate_saved(gs_gstate pgs) { return pgs; }
static int restore_page_device(gs_gstate pgs1, gs_gstate pgs2) { return 0; }
static int push_callout(i_ctx_t *ctx, const char *str) { return 0; }
static void gs_grestore(gs_gstate pgs) {}
static int zrestore(i_ctx_t *ctx) { return 0; }

#define check_type(a, b) (void)0