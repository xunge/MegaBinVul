#include <stdio.h>
#include <pthread.h>

struct drm_device {
    struct {
        pthread_mutex_t struct_mutex;
    };
};

struct drm_file {
    void *driver_priv;
};

struct drm_i915_private {
    struct {
        int has_logical_contexts;
    } caps;
};

struct drm_i915_file_private {
    int banned;
};

struct i915_gem_context {
    int user_handle;
};

struct drm_i915_gem_context_create {
    int pad;
    int ctx_id;
};

#define ENODEV 19
#define EINVAL 22
#define EIO 5

#define DRIVER_CAPS(x) (&(x)->caps)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define DRM_DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define PIDTYPE_PID 0

struct task_struct {
    char comm[16];
};
extern struct task_struct *current;

static inline struct drm_i915_private *to_i915(struct drm_device *dev) { return (struct drm_i915_private *)dev; }
static inline int pid_nr(void *pid) { return 0; }
static inline void *get_task_pid(struct task_struct *task, int type) { return NULL; }
static inline int i915_terminally_wedged(struct drm_i915_private *i915) { return 0; }
static inline int client_is_banned(struct drm_i915_file_private *file_priv) { return file_priv->banned; }
static inline int i915_mutex_lock_interruptible(struct drm_device *dev) { return pthread_mutex_lock(&dev->struct_mutex); }
static inline struct i915_gem_context *i915_gem_create_context(struct drm_i915_private *i915) { return NULL; }
static inline int gem_context_register(struct i915_gem_context *ctx, struct drm_i915_file_private *file_priv) { return 0; }
static inline void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static inline void context_close(struct i915_gem_context *ctx) {}