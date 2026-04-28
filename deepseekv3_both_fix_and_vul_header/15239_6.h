#include <stdio.h>
#include <errno.h>

typedef struct drm_r128_private {
    int cce_running;
} drm_r128_private_t;

struct drm_device {
    drm_r128_private_t *dev_private;
};

struct drm_file;

#define DRM_DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define EINVAL 22

void r128_do_cce_reset(drm_r128_private_t *dev_priv);