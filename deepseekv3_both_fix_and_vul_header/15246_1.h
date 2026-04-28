#include <stddef.h>
#include <sys/types.h>
#include <errno.h>

struct drm_device {
    struct drm_device_dma *dma;
    void *dev_private;
};

struct drm_device_dma {
    int buf_count;
};

struct drm_r128_blit {
    int idx;
};

typedef struct drm_r128_private {
    // 这里需要根据实际使用情况添加成员
} drm_r128_private_t;

typedef struct drm_r128_blit drm_r128_blit_t;

#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define DRM_DEBUG(fmt, ...)
#define DRM_CURRENTPID 0
#define DRM_ERROR(fmt, ...)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv) 
#define VB_AGE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING()

int r128_cce_dispatch_blit(struct drm_device *dev, struct drm_file *file_priv, drm_r128_blit_t *blit);