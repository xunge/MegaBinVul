#include <stdbool.h>
#include <stddef.h>

#define PAGE_SIZE 4096
#define MIGRATE_PFN_MIGRATE (1 << 0)
#define MIGRATEPAGE_SUCCESS 0
#define MMU_NOTIFY_MIGRATE 0
#define MIGRATE_SYNC_NO_COPY 0
#define VM_BUG_ON(cond) do { if (cond) {} } while (0)

struct page;
struct address_space;
struct vm_area_struct;
struct mm_struct;
struct folio;

struct mmu_notifier_range {
    unsigned int type;
    int flags;
    struct vm_area_struct *vma;
    struct mm_struct *mm;
    unsigned long start;
    unsigned long end;
    void *owner;
};

struct migrate_vma {
    unsigned long npages;
    unsigned long start;
    unsigned long end;
    unsigned long *src;
    unsigned long *dst;
    struct vm_area_struct *vma;
    void *pgmap_owner;
    struct page *fault_page;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct page *migrate_pfn_to_page(unsigned long pfn);
void mmu_notifier_range_init_owner(struct mmu_notifier_range *range,
                                 unsigned int type, int flags,
                                 struct vm_area_struct *vma,
                                 struct mm_struct *mm,
                                 unsigned long start,
                                 unsigned long end,
                                 void *owner);
void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range);
void mmu_notifier_invalidate_range_only_end(struct mmu_notifier_range *range);
void migrate_vma_insert_page(struct migrate_vma *migrate, unsigned long addr,
                           struct page *page, unsigned long *src);
bool is_device_private_page(struct page *page);
bool is_device_coherent_page(struct page *page);
bool is_zone_device_page(struct page *page);
struct address_space *page_mapping(struct page *page);
struct folio *page_folio(struct page *page);
int migrate_folio(struct address_space *mapping, struct folio *dst,
                 struct folio *src, int mode);
int migrate_folio_extra(struct address_space *mapping, struct folio *dst,
                       struct folio *src, int mode, int extra_count);