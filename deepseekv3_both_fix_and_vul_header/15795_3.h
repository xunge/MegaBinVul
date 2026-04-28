#include <stdbool.h>

struct drm_device {
    void *struct_mutex;
};

struct drm_i915_private {
    struct drm_device drm;
};

struct drm_file {
    struct drm_i915_file_private *driver_priv;
};

struct drm_i915_file_private {
    void *context_idr;
    void *context_idr_lock;
};

struct i915_gem_context {
    unsigned int user_handle;
};

#define DEFAULT_CONTEXT_HANDLE 0
#define GEM_BUG_ON(cond) do { if (cond) { } } while (0)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

void idr_init(void *idr);
void idr_destroy(void *idr);
void mutex_init(void *mutex);
void mutex_destroy(void *mutex);
void mutex_lock(void *mutex);
void mutex_unlock(void *mutex);

struct i915_gem_context *i915_gem_create_context(struct drm_i915_private *i915);
int gem_context_register(struct i915_gem_context *ctx, struct drm_i915_file_private *file_priv);
void context_close(struct i915_gem_context *ctx);
bool i915_gem_context_is_kernel(struct i915_gem_context *ctx);