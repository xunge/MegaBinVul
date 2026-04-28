#include <stdlib.h>
#include <string.h>

struct i915_gem_context {
    struct drm_i915_file_private *file_priv;
    void *pid;
    char *name;
    unsigned int user_handle;
    struct i915_address_space *ppgtt;
};

struct drm_i915_file_private {
    void *context_idr;
    void *context_idr_lock;
};

struct i915_address_space {
    struct {
        struct drm_i915_file_private *file;
    } vm;
};

struct task_struct {
    char comm[16];
};

extern struct task_struct *current;

#define GFP_KERNEL 0
#define ENOMEM 12
#define DEFAULT_CONTEXT_HANDLE 0
#define PIDTYPE_PID 0

static void *fetch_and_zero(void **ptr) {
    void *ret = *ptr;
    *ptr = NULL;
    return ret;
}

static int idr_alloc(void *idr, void *ptr, int start, int end, int gfp) {
    return 0;
}

static void mutex_lock(void *lock) {}
static void mutex_unlock(void *lock) {}

static char *kasprintf(int gfp, const char *fmt, ...) {
    return NULL;
}

static void kfree(const void *objp) {}
static void put_pid(void *pid) {}
static void *get_task_pid(void *task, int type) { return NULL; }
static int pid_nr(void *pid) { return 0; }