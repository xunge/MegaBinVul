#include <stdint.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define ENODEV 19
#define EFAULT 14

struct svm_range {
    unsigned long start;
    unsigned long last;
    uint32_t actual_loc;
    void *svms;
};

struct amdgpu_device;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
};
struct mm_struct;
struct page;

#define pr_debug(fmt, ...) 

long svm_migrate_vma_to_ram(struct amdgpu_device *adev, struct svm_range *prange,
                           struct vm_area_struct *vma, unsigned long addr,
                           unsigned long next, uint32_t trigger, ...);
struct amdgpu_device *svm_range_get_adev_by_id(struct svm_range *prange, uint32_t id);
void svm_range_vram_node_free(struct svm_range *prange);
struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);

#define min(a, b) ((a) < (b) ? (a) : (b))