#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

struct mutex {
    int dummy;
};

struct drm_device {
    void *dev_private;
    struct mutex struct_mutex;
};

struct drm_gem_object;
struct drm_file;

struct drm_i915_gem_pwrite {
    uint64_t data_ptr;
    size_t size;
    size_t offset;
};

struct drm_i915_gem_object {
    loff_t gtt_offset;
};

struct drm_i915_private {
    struct {
        void *gtt_mapping;
    } mm;
};

typedef struct drm_i915_private drm_i915_private_t;

#define to_intel_bo(obj) ((struct drm_i915_gem_object *)(obj))
#define PAGE_SIZE 4096
#define VERIFY_READ 0
#define EFAULT 14

typedef off_t loff_t;
typedef char* user_ptr_t;

#define __user

void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);

int access_ok(int type, const void *addr, unsigned long size);

extern int i915_gem_object_pin(struct drm_gem_object *obj, int flags);
extern int i915_gem_object_set_to_gtt_domain(struct drm_gem_object *obj, int write);
extern void i915_gem_object_unpin(struct drm_gem_object *obj);
extern int fast_user_write(void *mapping, loff_t page_base, int page_offset, user_ptr_t user_data, int page_length);