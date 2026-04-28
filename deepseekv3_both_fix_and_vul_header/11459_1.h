#include <stddef.h>
#include <stdbool.h>

typedef struct ref_s {
    int type;
} ref;

typedef struct i_ctx_s {
    struct gs_state_s *pgs;
} i_ctx_t;

typedef struct gs_state_s gs_state;
typedef struct gx_device_s gx_device;
typedef ref *os_ptr;

typedef struct alloc_save_s alloc_save_t;

extern os_ptr osp;
extern int t_save;
extern i_ctx_t *i_ctx_p;

#define igs (i_ctx_p->pgs)

struct gx_device_s {
    bool LockSafetyParams;
};

extern gs_state *gs_gstate_saved(gs_state *);
extern int restore_page_device(gs_state *, gs_state *);
extern int push_callout(i_ctx_t *, const char *);
extern void gs_grestore(gs_state *);
extern int zrestore(i_ctx_t *);
extern int restore_check_save(i_ctx_t *, alloc_save_t **);
extern int dorestore(i_ctx_t *, alloc_save_t *);
extern gx_device *gs_currentdevice_inline(gs_state *);

static inline void check_type(ref r, int type) {}