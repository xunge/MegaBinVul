#include <stdio.h>

struct drm_device {
    void *dev_private;
};

struct drm_file;

typedef struct drm_r128_private {
    int cce_running;
    int cce_mode;
} drm_r128_private_t;

#define R128_PM4_NONPM4 0
#define DRM_DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define LOCK_TEST_WITH_RETURN(dev, file_priv)

void r128_do_cce_start(drm_r128_private_t *dev_priv);