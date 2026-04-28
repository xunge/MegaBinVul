#include <errno.h>
#include <string.h>
#include <stddef.h>

#define DRM_ERROR(fmt, ...) 
#define DRM_DEBUG(fmt, ...) 
#define DRM_CURRENTPID 0
#define DRM_COPY_TO_USER(dest, src, size) (memcpy(dest, src, size) != NULL ? 0 : -EFAULT)
#define EINVAL 22
#define EFAULT 14

struct drm_device {
    void *dev_private;
};

struct drm_file;

struct drm_r128_private;
typedef struct drm_r128_private drm_r128_private_t;

struct drm_r128_getparam {
    int param;
    void *value;
};
typedef struct drm_r128_getparam drm_r128_getparam_t;

#define R128_PARAM_IRQ_NR 0

static inline int drm_dev_to_irq(struct drm_device *dev) { return 0; }