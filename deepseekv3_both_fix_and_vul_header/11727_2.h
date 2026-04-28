#include <stddef.h>

typedef struct gx_device_s {
    int LockSafetyParams;
    int ShowpageCount;
    int (*dev_spec_op)(struct gx_device_s *, int, void *, int);
} gx_device;

typedef struct os_ptr_s {
    struct {
        gx_device *pdevice;
    } value;
} *os_ptr;

typedef struct i_ctx_s i_ctx_t;
typedef struct gs_state_s gs_state;

extern gs_state *igs;
extern gs_state *istate;
extern os_ptr osp;

enum {
    t_device,
    gs_error_invalidaccess,
    gs_error_undefined,
    gxdso_current_output_device,
    dev_spec_op
};

#define check_write_type(op, type) 
#define return_error(err) return err
#define make_bool(op, val) 
#define gs_note_error(err) err
#define invalidate_stack_devices(ctx) 
#define clear_pagedevice(state) 
#define dev_proc(dev, proc) (dev)->proc

int gs_setdevice_no_erase(gs_state *state, gx_device *dev);
gx_device *gs_currentdevice(gs_state *state);