#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define UINT_MAX (~0U)
#define GFP_KERNEL 0
#define __GFP_NOWARN 0
#define __GFP_NORETRY 0
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14

struct drm_device;
struct drm_file;

struct drm_i915_gem_execbuffer2 {
    uint32_t buffer_count;
    uint64_t buffers_ptr;
};

struct drm_i915_gem_exec_object2 {
    uint32_t handle;
    uint32_t offset;
};

struct drm_i915_relocation_entry {
    uint32_t target_handle;
    uint32_t delta;
};

#define __user
#define uintptr_t unsigned long

#define DRM_DEBUG(fmt, ...)

void* kmalloc(size_t size, int flags);
void* drm_malloc_ab(size_t size, size_t count);
void drm_free_large(void *ptr);
int copy_from_user(void *to, const void *from, size_t n);
int copy_to_user(void *to, const void *from, size_t n);

int i915_gem_do_execbuffer(struct drm_device *dev, void *data,
                         struct drm_file *file,
                         struct drm_i915_gem_execbuffer2 *args,
                         struct drm_i915_gem_exec_object2 *exec2_list);