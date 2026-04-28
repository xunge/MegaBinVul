#include <stddef.h>
#include <errno.h>

struct drm_device {
    void *dev_private;
    struct drm_device_dma *dma;
};

struct drm_file {
    int dummy;
};

struct drm_device_dma {
    int buf_count;
    struct drm_buf **buflist;
};

struct drm_buf {
    void *dev_private;
    struct drm_file *file_priv;
    int pending;
    unsigned int used;
};

struct drm_r128_private {
    int dummy;
};

struct drm_r128_buf_priv {
    int discard;
};

struct drm_r128_indirect {
    int idx;
    int start;
    int end;
    int discard;
};

typedef struct drm_r128_private drm_r128_private_t;
typedef struct drm_r128_buf_priv drm_r128_buf_priv_t;
typedef struct drm_r128_indirect drm_r128_indirect_t;

#define DRM_CURRENTPID 0
#define DRM_ERROR(fmt, ...)
#define DRM_DEBUG(fmt, ...)

#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv)
#define VB_AGE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING()

void r128_cce_dispatch_indirect(struct drm_device *dev, struct drm_buf *buf, int start, int end);