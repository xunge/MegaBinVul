#include <stddef.h>
#include <stdarg.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct gs_state_s gs_state;

extern gs_state *igs;

int restore_page_device_3args(i_ctx_t *i_ctx_p, gs_state *igs, gs_state *saved);
int restore_page_device_2args(gs_state *igs, gs_state *saved);
int gs_grestore(gs_state *igs);
gs_state *gs_gstate_saved(gs_state *igs);
int push_callout(i_ctx_t *i_ctx_p, const char *str);

static inline int restore_page_device(i_ctx_t *i_ctx_p, ...) {
    va_list args;
    gs_state *igs, *saved;
    va_start(args, i_ctx_p);
    if (i_ctx_p) {
        igs = va_arg(args, gs_state*);
        saved = va_arg(args, gs_state*);
        va_end(args);
        return restore_page_device_3args(i_ctx_p, igs, saved);
    } else {
        igs = va_arg(args, gs_state*);
        saved = va_arg(args, gs_state*);
        va_end(args);
        return restore_page_device_2args(igs, saved);
    }
}