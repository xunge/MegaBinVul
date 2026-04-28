#include <stddef.h>

struct drm_file {
    void *driver_priv;
};

struct drm_i915_file_private {
    struct drm_i915_private *dev_priv;
    struct {
        int unused;
    } context_idr;
    struct {
        int unused;
    } context_idr_lock;
};

struct drm_i915_private {
    struct {
        struct {
            int unused;
        } struct_mutex;
    } drm;
};

static void context_idr_cleanup(int id, void *p, void *data)
{
}