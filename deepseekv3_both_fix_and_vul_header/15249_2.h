#include <stdint.h>

struct drm_device {
    void *dev_private;
};

struct drm_file;

typedef struct drm_r128_private {
    struct drm_r128_sarea *sarea_priv;
} drm_r128_private_t;

typedef struct drm_r128_sarea {
    int nbox;
    uint32_t dirty;
} drm_r128_sarea_t;

typedef struct drm_r128_clear {
} drm_r128_clear_t;

#define DRM_DEBUG(fmt)
#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv) 
#define R128_NR_SAREA_CLIPRECTS 16
#define R128_UPLOAD_CONTEXT 0x1
#define R128_UPLOAD_MASKS 0x2
#define COMMIT_RING()

void r128_cce_dispatch_clear(struct drm_device *dev, drm_r128_clear_t *clear);