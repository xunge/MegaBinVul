#include <stddef.h>

struct drm_device {
    int num_crtcs;
};

struct drm_file;

struct drm_modeset_ctl {
    int crtc;
    int cmd;
};

#define _DRM_PRE_MODESET 0
#define _DRM_POST_MODESET 1
#define EINVAL 22

void drm_vblank_pre_modeset(struct drm_device *dev, int crtc);
void drm_vblank_post_modeset(struct drm_device *dev, int crtc);