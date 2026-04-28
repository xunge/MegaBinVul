#include <stddef.h>
#include <stdint.h>

typedef uint64_t u64;

#define NE_MIN_MEM_REGION_SIZE (2 * 1024 * 1024)
#define NE_ERR_MEM_MAX_REGIONS (-1000)
#define SLOT_ADD_MEM (0)
#define GFP_KERNEL 0
#define FOLL_GET 0
#define EINVAL 22
#define ENOMEM 12

struct list_head {
    struct list_head *next, *prev;
};

struct page {
    unsigned long flags;
};

struct pci_dev {
    unsigned int dummy;
};

struct miscdevice {
    void *this_device;
};

struct ne_enclave {
    unsigned long long max_mem_regions;
    unsigned long long nr_mem_regions;
    unsigned long long mem_size;
    unsigned long long slot_uid;
    struct list_head mem_regions_list;
};

struct ne_user_memory_region {
    unsigned long long memory_size;
    unsigned long userspace_addr;
};

struct ne_mem_region {
    unsigned long memory_size;
    unsigned long userspace_addr;
    unsigned long nr_pages;
    struct page **pages;
    struct list_head mem_region_list_entry;
};

struct ne_pci_dev {
    struct pci_dev *pdev;
};

struct ne_devs {
    struct ne_pci_dev *ne_pci_dev;
};

struct ne_pci_dev_cmd_reply {
    int dummy;
};

struct slot_add_mem_req {
    unsigned long long slot_uid;
    unsigned long long paddr;
    unsigned long long size;
};

extern struct ne_devs ne_devs;
extern struct miscdevice ne_misc_dev;

static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void *kcalloc(size_t n, size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline void put_page(struct page *page) {}
static inline unsigned long page_size(struct page *page) { return 0; }
static inline unsigned long page_to_phys(struct page *page) { return 0; }
static inline int IS_ALIGNED(unsigned long addr, unsigned long align) { return 0; }
static inline void list_add(struct list_head *new, struct list_head *head) {}
static inline long get_user_pages(unsigned long start, int nr_pages, int gup_flags, struct page **pages, void **vmas) { return 0; }
static inline long get_user_pages_unlocked(unsigned long start, int nr_pages, struct page **pages, int gup_flags) { return 0; }
static inline void dev_err_ratelimited(void *dev, const char *fmt, ...) {}

int ne_sanity_check_user_mem_region(struct ne_enclave *ne_enclave, struct ne_user_memory_region mem_region);
int ne_sanity_check_user_mem_region_page(struct ne_enclave *ne_enclave, struct page *page);
int ne_do_request(struct pci_dev *pdev, unsigned int cmd, void *req, size_t req_size, void *reply, size_t reply_size);