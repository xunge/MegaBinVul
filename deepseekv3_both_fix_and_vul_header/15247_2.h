#include <stdint.h>
#include <errno.h>

typedef uint32_t u32;

struct drm_device {
    void *dev_private;
};
struct drm_file;

typedef struct drm_r128_private {
    // placeholder for private data
} drm_r128_private_t;

typedef struct drm_r128_stipple {
    u32 *mask;
} drm_r128_stipple_t;

#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING() 
#define DRM_COPY_FROM_USER(dest, src, size) (0)

int r128_cce_dispatch_stipple(struct drm_device *dev, u32 mask[32]);