#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define ENOMEM 12
#define GFP_KERNEL 0
#define MIGRATE_VMA_SELECT_SYSTEM 0

struct device {
    int id;
};

struct amdgpu_device {
    struct {
        struct device *dev;
        int id;
    } kfd;
    struct device *dev;
};

struct svm_range {
    unsigned long start;
    unsigned long last;
    int prefetch_loc;
    int preferred_loc;
    void *svms;
};

struct vm_area_struct {};

struct kfd_process {
    struct {
        pid_t pid;
    } *lead_thread;
    void *svms;
};

struct kfd_process_device {
    unsigned long page_in;
};

struct dma_fence {};

struct migrate_vma {
    struct vm_area_struct *vma;
    uint64_t start;
    uint64_t end;
    unsigned long flags;
    void *pgmap_owner;
    void *src;
    void *dst;
    unsigned long cpages;
    unsigned long npages;
};

typedef uint64_t dma_addr_t;

#define SVM_ADEV_PGMAP_OWNER(adev) (adev)
#define WRITE_ONCE(var, val) (var = val)
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static void *kvcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static void kvfree(void *p) { free(p); }
static void dev_err(struct device *dev, const char *fmt, ...) {}
static void pr_debug(const char *fmt, ...) {}

static void kfd_smi_event_migration_start(struct device *dev, pid_t pid, unsigned long start, unsigned long end, int dst, int src, int prefetch_loc, int preferred_loc, uint32_t trigger) {}
static void kfd_smi_event_migration_end(struct device *dev, pid_t pid, unsigned long start, unsigned long end, int dst, int src, uint32_t trigger) {}
static int migrate_vma_setup(struct migrate_vma *migrate) { return 0; }
static void migrate_vma_pages(struct migrate_vma *migrate) {}
static void migrate_vma_finalize(struct migrate_vma *migrate) {}
static int svm_migrate_copy_to_vram(struct amdgpu_device *adev, struct svm_range *prange, struct migrate_vma *migrate, struct dma_fence **mfence, dma_addr_t *scratch) { return 0; }
static void svm_migrate_copy_done(struct amdgpu_device *adev, struct dma_fence *mfence) {}
static unsigned long svm_migrate_successful_pages(struct migrate_vma *migrate) { return 0; }
static void svm_range_dma_unmap(struct device *dev, dma_addr_t *scratch, int start, uint64_t npages) {}
static void svm_range_free_dma_mappings(struct svm_range *prange) {}
static struct kfd_process_device *svm_range_get_pdd_by_adev(struct svm_range *prange, struct amdgpu_device *adev) { return NULL; }