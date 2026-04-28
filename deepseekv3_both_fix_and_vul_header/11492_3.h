#include <stdbool.h>

typedef struct gs_gstate gs_gstate;
typedef struct gx_device gx_device;

struct gs_int_gstate {
    void* pagedevice;
};

struct gx_device {
    void* memory;
    bool LockSafetyParams;
    gx_device* (*get_page_device)(gx_device*);
};

typedef int* os_ptr;

typedef struct ref_stack_s {
    int count;
} ref_stack;

typedef struct i_ctx_t i_ctx_t;

extern os_ptr osp;
extern os_ptr osbot;
extern ref_stack o_stack;

#define gs_error_stackoverflow 1
#define return_error(code) (code)

bool obj_eq(void* memory, void* a, void* b);
gx_device* gs_currentdevice(const gs_gstate* pgs);
struct gs_int_gstate* gs_int_gstate(const gs_gstate* pgs);
int ref_stack_count(ref_stack* stack);
#define dev_proc(dev, proc) (dev->proc)

static inline int os_ptr_diff(os_ptr a, os_ptr b) {
    return a - b;
}