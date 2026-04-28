#include <stdlib.h>
#include <stdbool.h>

struct kref {
    int count;
};

struct drm_mode_config {
    unsigned int num_crtc;
    unsigned int num_total_plane;
};

struct drm_device {
    struct drm_mode_config mode_config;
};

struct drm_atomic_state {
    struct kref ref;
    bool allow_modeset;
    void *crtcs;
    void *planes;
    struct drm_device *dev;
};

#define GFP_KERNEL 0
#define ENOMEM 12

static inline void kref_init(struct kref *kref) {
    kref->count = 1;
}

static void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static void drm_dbg_atomic(struct drm_device *dev, const char *fmt, ...) {}

static void drm_atomic_state_default_release(struct drm_atomic_state *state) {
    free(state->crtcs);
    free(state->planes);
}