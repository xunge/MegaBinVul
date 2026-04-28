#include <stdbool.h>
#include <stddef.h>

typedef struct i_ctx_s i_ctx_t;
typedef struct alloc_save_s alloc_save_t;
typedef struct gs_state_s gs_state;
typedef struct gx_device_s gx_device;

extern gs_state *igs;

struct gx_device_s {
    bool LockSafetyParams;
};

struct gs_state_s {
    gs_state *saved;
    gx_device *device;
};

static inline gx_device *gs_currentdevice_inline(gs_state *pgs) { return pgs->device; }
static int restore_check_save(i_ctx_t *, alloc_save_t **);
static int restore_page_device(gs_state *, gs_state *);
static int push_callout(i_ctx_t *, const char *);
static void gs_grestore(gs_state *pgs) { pgs = pgs->saved; }
static gs_state *gs_gstate_saved(gs_state *pgs) { return pgs->saved; }
static int dorestore(i_ctx_t *, alloc_save_t *);
static int zrestore(i_ctx_t *);

typedef struct ref_s {
    int type;
} ref;
#define t_save 0
typedef ref *os_ptr;
extern os_ptr osp;

static void check_type(ref r, int type) {}