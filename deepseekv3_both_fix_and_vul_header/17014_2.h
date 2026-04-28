#include <stdlib.h>
#include <stddef.h>

struct drm_crtc {
    struct drm_crtc_state *state;
};

struct drm_crtc_state {
    int dummy; // Placeholder for minimal definition
};

struct malidp_crtc_state {
    struct drm_crtc_state base;
};

#define GFP_KERNEL 0

void *kzalloc(size_t size, int flags);
void malidp_crtc_destroy_state(struct drm_crtc *crtc, struct drm_crtc_state *state);
void __drm_atomic_helper_crtc_reset(struct drm_crtc *crtc, struct drm_crtc_state *state);