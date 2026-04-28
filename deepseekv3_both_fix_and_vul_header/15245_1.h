#include <stddef.h>
#include <sys/types.h>

#define DRM_CURRENTPID 0
#define EINVAL 22

#define LOCK_TEST_WITH_RETURN(dev, file_priv)
#define RING_SPACE_TEST_WITH_RETURN(dev_priv)
#define VB_AGE_TEST_WITH_RETURN(dev_priv)
#define COMMIT_RING()
#define DRM_ERROR(fmt, ...)
#define DRM_DEBUG(fmt, ...)

struct drm_device {
    void *dev_private;
    struct drm_device_dma *dma;
};

struct drm_file {
    // dummy structure
};

struct drm_device_dma {
    int buf_count;
    struct drm_buf **buflist;
};

struct drm_buf {
    void *dev_private;
    struct drm_file *file_priv;
    int pending;
    int used;
};

struct drm_r128_private {
    // dummy structure
};

struct drm_r128_buf_priv {
    int prim;
    int discard;
};

struct drm_r128_vertex {
    int idx;
    int count;
    int discard;
    int prim;
};

typedef struct drm_r128_private drm_r128_private_t;
typedef struct drm_r128_buf_priv drm_r128_buf_priv_t;
typedef struct drm_r128_vertex drm_r128_vertex_t;

enum {
    R128_CCE_VC_CNTL_PRIM_TYPE_TRI_TYPE2
};