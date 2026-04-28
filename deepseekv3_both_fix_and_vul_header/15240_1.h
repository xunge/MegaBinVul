#include <stddef.h>

struct drm_device {
    void *dev_private;
};

struct drm_file;

struct drm_r128_private;

struct drm_r128_cce_stop {
    int flush;
    int idle;
};

typedef struct drm_r128_private drm_r128_private_t;
typedef struct drm_r128_cce_stop drm_r128_cce_stop_t;

#define DRM_DEBUG(fmt, ...)
#define LOCK_TEST_WITH_RETURN(dev, file_priv)

int r128_do_cce_flush(drm_r128_private_t *dev_priv);
int r128_do_cce_idle(drm_r128_private_t *dev_priv);
void r128_do_cce_stop(drm_r128_private_t *dev_priv);
void r128_do_engine_reset(struct drm_device *dev);