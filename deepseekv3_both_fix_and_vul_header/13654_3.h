#include <stdlib.h>
#include <stdint.h>

struct drm_device;
struct drm_file {
    void *driver_priv;
};

struct mutex {
    int dummy;
};

struct ww_acquire_ctx {
    int dummy;
};

struct v3d_dev {
    struct drm_device *drm;
    struct mutex sched_lock;
};

struct v3d_file_priv;

struct v3d_job {
    void *bo;
    int bo_count;
    void *deps;
    void *done_fence;
};

struct v3d_bin_job {
    struct v3d_job base;
    uint32_t start;
    uint32_t end;
    uint32_t qma;
    uint32_t qms;
    uint32_t qts;
    struct v3d_render_job *render;
};

struct v3d_render_job {
    struct v3d_job base;
    uint32_t start;
    uint32_t end;
    void *unref_list;
};

struct drm_v3d_submit_cl {
    uint32_t pad;
    uint32_t rcl_start;
    uint32_t rcl_end;
    uint32_t bcl_start;
    uint32_t bcl_end;
    uint32_t qma;
    uint32_t qms;
    uint32_t qts;
    uint32_t *bo_handles;
    uint32_t bo_handle_count;
    uint32_t in_sync_rcl;
    uint32_t in_sync_bcl;
    uint32_t out_sync;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define EINVAL 2

#define DRM_INFO(fmt, ...)
#define trace_v3d_submit_cl_ioctl(...)
#define INIT_LIST_HEAD(ptr)
#define dma_fence_get(fence) NULL
#define kcalloc(n, size, flags) malloc((n)*(size))
#define kfree(ptr) free(ptr)
#define mutex_lock(lock)
#define mutex_unlock(lock)

#define V3D_BIN 0
#define V3D_RENDER 1

static inline struct v3d_dev *to_v3d_dev(struct drm_device *dev) {
    return (struct v3d_dev *)dev;
}

int v3d_job_init(struct v3d_dev *v3d, struct drm_file *file_priv,
                struct v3d_job *job, void (*free)(struct v3d_job *),
                uint32_t in_sync);
void v3d_job_put(struct v3d_job *job);
int v3d_lookup_bos(struct drm_device *dev, struct drm_file *file_priv,
                  struct v3d_job *job, uint32_t *handles, uint32_t count);
int v3d_lock_bo_reservations(struct v3d_job *job, struct ww_acquire_ctx *ctx);
int v3d_push_job(struct v3d_file_priv *v3d_priv, struct v3d_job *job, int type);
void v3d_attach_fences_and_unlock_reservation(struct drm_file *file_priv,
                                            struct v3d_job *job,
                                            struct ww_acquire_ctx *ctx,
                                            uint32_t out_sync,
                                            void *done_fence);
int drm_gem_fence_array_add(void *deps, void *fence);
void drm_gem_unlock_reservations(void *bo, int count, struct ww_acquire_ctx *ctx);

void v3d_render_job_free(struct v3d_job *job);
void v3d_job_free(struct v3d_job *job);