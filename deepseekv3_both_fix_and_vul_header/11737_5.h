#include <stdbool.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct ref_stack_s ref_stack;
typedef struct gs_gstate_s gs_gstate;
typedef struct i_ctx_s i_ctx_t;

struct obj_s {
    int dummy;
};

struct gx_device_s {
    gs_memory_t *memory;
    bool LockSafetyParams;
    struct gx_device_s* (*get_page_device)(struct gx_device_s*);
};

struct gs_int_gstate_s {
    struct obj_s pagedevice;
};

typedef struct gx_device_s gx_device;

extern gx_device *gs_currentdevice(const gs_gstate *);
extern struct gs_int_gstate_s *gs_int_gstate(const gs_gstate *);
extern bool obj_eq(gs_memory_t *, struct obj_s *, struct obj_s *);
extern int ref_stack_count(ref_stack *);
extern int ref_stack_max_count(ref_stack *);
extern int return_error(int);

#define gs_error_stackoverflow 1
#define gs_error_execstackoverflow 2

extern ref_stack o_stack;
extern ref_stack e_stack;

#define dev_proc(dev, proc) (dev->proc)