#include <stdint.h>
#include <string.h>
#include <stdbool.h>

struct amdgpu_device;
struct drm_file;

struct dma_fence {
    int error;
};

struct drm_amdgpu_fence {
    // Minimal definition needed for compilation
    unsigned int handle;
};

union drm_amdgpu_wait_fences {
    struct {
        uint32_t fence_count;
        uint64_t timeout_ns;
    } in;
    struct {
        int status;
    } out;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

long dma_fence_wait_timeout(struct dma_fence *fence, bool intr, unsigned long timeout);
void dma_fence_put(struct dma_fence *fence);
struct dma_fence *amdgpu_cs_get_fence(struct amdgpu_device *adev, struct drm_file *filp, struct drm_amdgpu_fence *fence);
unsigned long amdgpu_gem_timeout(uint64_t timeout_ns);