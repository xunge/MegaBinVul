#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct mutex {
    int dummy;
};

struct drm_clip_rect {
    int x1, y1, x2, y2;
};

struct drm_device {
    struct {
        struct mutex mutex;
    } mode_config;
};

struct drm_file;
struct drm_mode_object;
struct drm_framebuffer {
    struct {
        int (*dirty)(struct drm_framebuffer *, struct drm_file *, unsigned, int, struct drm_clip_rect *, int);
    } *funcs;
};

struct drm_mode_fb_dirty_cmd {
    int fb_id;
    int num_clips;
    unsigned long clips_ptr;
    unsigned flags;
    int color;
};

#define DRIVER_MODESET 0
#define DRM_MODE_OBJECT_FB 0
#define DRM_MODE_FB_DIRTY_FLAGS 0
#define DRM_MODE_FB_DIRTY_ANNOTATE_COPY 0
#define DRM_MODE_FB_DIRTY_MAX_CLIPS 0
#define EINVAL 1
#define ENOMEM 1
#define EFAULT 1
#define ENOSYS 1
#define GFP_KERNEL 0

#define __user
#define mutex_lock(m) (void)0
#define mutex_unlock(m) (void)0
#define DRM_ERROR(fmt, ...) (void)0

static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *p) {}

static inline bool drm_core_check_feature(struct drm_device *dev, int feature) { return false; }
static inline struct drm_mode_object *drm_mode_object_find(struct drm_device *dev, int id, int type) { return NULL; }
static inline struct drm_framebuffer *obj_to_fb(struct drm_mode_object *obj) { return NULL; }