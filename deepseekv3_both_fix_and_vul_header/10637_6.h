#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <linux/errno.h>

#define DRM_VMW_MAX_MIP_LEVELS 20
#define SVGA3D_INVALID_ID 0xFFFFFFFF
#define PAGE_SIZE 4096
#define EINVAL 22

#define unlikely(x) (x)
#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define drm_vmw_surface_flag_scanout (1 << 0)
#define drm_vmw_surface_flag_create_buffer (1 << 1)
#define drm_vmw_surface_flag_shareable (1 << 2)

struct drm_device;
struct drm_file {
    struct drm_master *master;
};
struct drm_master;
struct ttm_object_file;
struct ttm_base_object;
struct ttm_prime_object {
    struct {
        struct {
            unsigned long key;
        } hash;
    } base;
};
struct vmw_dma_buffer {
    struct {
        unsigned long num_pages;
        struct {
            unsigned long vma_node;
        } vma_node;
    } base;
};
struct vmw_resource {
    struct vmw_dma_buffer *backup;
    uint32_t backup_size;
};
struct vmw_surface {
    struct vmw_resource res;
};
struct vmw_user_surface {
    struct vmw_surface srf;
    struct drm_master *master;
    struct ttm_prime_object prime;
    struct ttm_base_object *backup_base;
};
struct ww_mutex {
    int dummy;
};
struct vmw_private {
    struct ttm_object_file *tfile;
    struct ww_mutex reservation_sem;
};
struct drm_vmw_size {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
};
struct drm_vmw_gb_surface_create_req {
    uint32_t multisample_count;
    uint32_t mip_levels;
    uint32_t svga3d_flags;
    uint32_t format;
    uint32_t drm_surface_flags;
    uint32_t array_size;
    struct drm_vmw_size base_size;
    uint32_t buffer_handle;
};
struct drm_vmw_gb_surface_create_rep {
    uint32_t handle;
    uint32_t backup_size;
    uint64_t buffer_map_handle;
    uint32_t buffer_size;
    uint32_t buffer_handle;
};
union drm_vmw_gb_surface_create_arg {
    struct drm_vmw_gb_surface_create_req req;
    struct drm_vmw_gb_surface_create_rep rep;
};

enum ttm_object_type {
    VMW_RES_SURFACE
};
enum ttm_ref_type;

extern struct vmw_private *vmw_priv(struct drm_device *dev);
extern struct vmw_private *vmw_fpriv(struct drm_file *file_priv);
extern size_t vmw_user_surface_size;
extern int vmw_surface_gb_priv_define(struct drm_device *dev, uint32_t size,
                                     uint32_t svga3d_flags, uint32_t format,
                                     bool scanout, uint32_t mip_levels,
                                     uint32_t multisample_count,
                                     uint32_t array_size,
                                     struct drm_vmw_size base_size,
                                     struct vmw_surface **srf_out);
extern int vmw_user_dmabuf_lookup(struct ttm_object_file *tfile,
                                 uint32_t handle, struct vmw_dma_buffer **out,
                                 struct ttm_base_object **base);
extern int vmw_user_dmabuf_alloc(struct vmw_private *dev_priv,
                                 struct ttm_object_file *tfile,
                                 uint32_t size, bool shareable,
                                 uint32_t *handle, struct vmw_dma_buffer **out,
                                 struct ttm_base_object **base);
extern void vmw_dmabuf_unreference(struct vmw_dma_buffer **buf);
extern void vmw_resource_unreference(struct vmw_resource **res);
extern struct vmw_resource *vmw_resource_reference(struct vmw_resource *res);
extern int ttm_prime_object_init(struct ttm_object_file *tfile,
                                uint32_t size, struct ttm_prime_object *prime,
                                bool shareable, enum ttm_object_type type,
                                void (*refcount_release)(struct ttm_base_object **),
                                void (*ref_obj_release)(struct ttm_base_object *,
                                                       enum ttm_ref_type));
extern void vmw_user_surface_base_release(struct ttm_base_object **base);
extern bool drm_is_primary_client(struct drm_file *file_priv);
extern struct drm_master *drm_master_get(struct drm_master *master);
extern uint64_t drm_vma_node_offset_addr(void *node);
extern size_t ttm_round_pot(size_t size);
extern int ttm_read_lock(struct ww_mutex *sem, bool interruptible);
extern void ttm_read_unlock(struct ww_mutex *sem);
extern void DRM_ERROR(const char *fmt, ...);