#include <stdint.h>

#define DRM_DEBUG(fmt, ...)
#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING()

#define R128_NR_SAREA_CLIPRECTS 0
#define R128_UPLOAD_CONTEXT 0
#define R128_UPLOAD_MASKS 0

struct drm_file;

typedef struct {
    uint32_t dirty;
    int nbox;
} drm_r128_sarea_t;

typedef struct {
    drm_r128_sarea_t *sarea_priv;
} drm_r128_private_t;

struct drm_device {
    drm_r128_private_t *dev_private;
};

void r128_cce_dispatch_swap(struct drm_device *dev);