#include <stdbool.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct obj_s {
    int dummy;
} obj_t;
typedef struct gs_gstate_s gs_gstate;
typedef struct gx_device_s {
    gs_memory_t *memory;
    bool LockSafetyParams;
    int (*procs[1])(struct gx_device_s *);
} gx_device;
typedef struct gs_int_gstate_s {
    obj_t pagedevice;
} gs_int_gstate_t;
typedef struct i_ctx_s i_ctx_t;
typedef struct ref_stack_s {
    int count;
    int max_count;
} ref_stack_t;
typedef int *os_ptr;

#define get_page_device 0

extern gx_device *gs_currentdevice(const gs_gstate *);
extern gs_int_gstate_t *gs_int_gstate(const gs_gstate *);
extern bool obj_eq(gs_memory_t *, const obj_t *, const obj_t *);
extern int (*dev_proc(gx_device *, int))(gx_device *);
extern int ref_stack_count(const ref_stack_t *);
extern int ref_stack_max_count(const ref_stack_t *);
extern os_ptr osp;
extern os_ptr osbot;
extern ref_stack_t o_stack;
extern ref_stack_t e_stack;
extern int return_error(int);
#define gs_error_stackoverflow 1
#define gs_error_execstackoverflow 2