#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct kref {
    int refcount;
};

struct drm_mode_config_funcs {
    void (*atomic_state_free)(void*);
};

struct drm_mode_config {
    struct drm_mode_config_funcs *funcs;
};

struct drm_device {
    struct drm_mode_config mode_config;
};

struct drm_atomic_state {
    struct kref ref;
    struct drm_device *dev;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void drm_atomic_state_clear(struct drm_atomic_state *state);
void drm_dbg_atomic(struct drm_device *dev, const char *fmt, ...);
void drm_atomic_state_default_release(struct drm_atomic_state *state);
void kfree(void *ptr);