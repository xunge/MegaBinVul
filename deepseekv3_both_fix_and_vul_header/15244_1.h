#include <stdint.h>
#include <unistd.h>

typedef uint16_t u16;
#define EINVAL 22

#define DRM_CURRENTPID getpid()
#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define DRM_ERROR(fmt, ...)
#define DRM_DEBUG(fmt, ...)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv)
#define VB_AGE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING()

#define R128_CCE_VC_CNTL_PRIM_TYPE_TRI_TYPE2 0
#define R128_INDEX_PRIM_OFFSET 0

struct drm_device {
    void *dev_private;
    struct drm_device_dma *dma;
};

struct drm_device_dma {
    int buf_count;
    struct drm_buf **buflist;
};

struct drm_buf {
    void *dev_private;
    void *file_priv;
    int pending;
    unsigned int used;
};

struct drm_file;

typedef struct {
    int idx;
    int start;
    int end;
    int discard;
    int prim;
} drm_r128_indices_t;

typedef struct {
    int prim;
    int discard;
} drm_r128_buf_priv_t;

typedef struct {
} drm_r128_private_t;

void r128_cce_dispatch_indices(struct drm_device *dev, struct drm_buf *buf, int start, int end, int count);