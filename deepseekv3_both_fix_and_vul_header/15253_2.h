#include <stddef.h>

struct drm_device {
    void *dev_private;
};

struct drm_file;

typedef struct drm_r128_private {
    int page_flipping;
} drm_r128_private_t;

#define DRM_DEBUG(fmt, ...)
#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING()

static void r128_do_init_pageflip(struct drm_device *dev) {}
static void r128_cce_dispatch_flip(struct drm_device *dev) {}