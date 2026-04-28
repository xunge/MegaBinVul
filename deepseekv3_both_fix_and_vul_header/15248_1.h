#include <stdint.h>
#include <errno.h>

struct drm_device {
    void *dev_private;
};

struct drm_r128_depth {
    int func;
};

struct drm_file;
struct drm_r128_private;

typedef struct drm_r128_private drm_r128_private_t;
typedef struct drm_r128_depth drm_r128_depth_t;

#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv) 
#define COMMIT_RING()

#define R128_WRITE_SPAN 0
#define R128_WRITE_PIXELS 1
#define R128_READ_SPAN 2
#define R128_READ_PIXELS 3

int r128_cce_dispatch_write_span(struct drm_device *dev, drm_r128_depth_t *depth);
int r128_cce_dispatch_write_pixels(struct drm_device *dev, drm_r128_depth_t *depth);
int r128_cce_dispatch_read_span(struct drm_device *dev, drm_r128_depth_t *depth);
int r128_cce_dispatch_read_pixels(struct drm_device *dev, drm_r128_depth_t *depth);