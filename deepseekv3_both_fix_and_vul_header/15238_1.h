#include <stdio.h>
#include <stdlib.h>

struct drm_device {
    void *dev_private;
};

struct drm_file;

typedef struct drm_r128_private {
    int cce_running;
} drm_r128_private_t;

#define DRM_DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define LOCK_TEST_WITH_RETURN(dev, file_priv) 

int r128_do_cce_flush(drm_r128_private_t *dev_priv);
int r128_do_cce_idle(drm_r128_private_t *dev_priv);