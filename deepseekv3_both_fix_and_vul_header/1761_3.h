#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef uint64_t dma_addr_t;

struct device {
    int id;
};

struct amdgpu_device {
    struct device *dev;
    struct {
        struct device *dev;
        int id;
    } kfd;
    struct {
        struct {
            struct {
                int connected_to_cpu;
            } xgmi;
        } gmc;
    };
};

struct svm_range {
    struct {
        struct kfd_process *svms;
    };
    uint64_t start;
    uint64_t last;
    int prefetch_loc;
    int preferred_loc;
};

struct kfd_process {
    struct {
        int pid;
    } *lead_thread;
    struct {
        struct kfd_process *svms;
    };
};

struct kfd_process_device {
    unsigned long page_out;
};

struct vm_area_struct;
struct page;
struct dma_fence;

#define PAGE_SHIFT 12
#define ENOMEM 12
#define GFP_KERNEL 0
#define SVM_ADEV_PGMAP_OWNER(adev) ((unsigned long)(adev))

#define MIGRATE_VMA_SELECT_DEVICE_COHERENT 0
#define MIGRATE_VMA_SELECT_DEVICE_PRIVATE 0

struct migrate_vma {
    struct vm_area_struct *vma;
    unsigned long start;
    unsigned long end;
    unsigned long pgmap_owner;
    unsigned long flags;
    unsigned long *src;
    unsigned long *dst;
    struct page *fault_page;
    unsigned long cpages;
    unsigned long npages;
};

static inline void *kvcalloc(size_t n, size_t size, int flags) { return NULL; }
static inline void kvfree(const void *addr) {}
static inline int migrate_vma_setup(struct migrate_vma *args) { return 0; }
static inline void migrate_vma_pages(struct migrate_vma *args) {}
static inline void migrate_vma_finalize(struct migrate_vma *args) {}
static inline void kfd_smi_event_migration_start(struct device *dev, int pid, unsigned long start, unsigned long end, int dev_id, int dummy1, int prefetch_loc, int preferred_loc, int trigger) {}
static inline void kfd_smi_event_migration_end(struct device *dev, int pid, unsigned long start, unsigned long end, int dev_id, int dummy1, int trigger) {}
static inline unsigned long svm_migrate_unsuccessful_pages(struct migrate_vma *migrate) { return 0; }
static inline int svm_migrate_copy_to_ram(struct amdgpu_device *adev, struct svm_range *prange, struct migrate_vma *migrate, struct dma_fence **mfence, dma_addr_t *scratch, uint64_t npages) { return 0; }
static inline void svm_migrate_copy_done(struct amdgpu_device *adev, struct dma_fence *mfence) {}
static inline void svm_range_dma_unmap(struct device *dev, dma_addr_t *scratch, int offset, uint64_t npages) {}
static inline struct kfd_process_device *svm_range_get_pdd_by_adev(struct svm_range *prange, struct amdgpu_device *adev) { return NULL; }
#define WRITE_ONCE(x, val) (x = val)
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_err(dev, fmt, ...) printf(fmt, ##__VA_ARGS__)