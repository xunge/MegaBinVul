#include <stddef.h>
#include <stdint.h>

#define __user

struct sclp_ctl_sccb {
    unsigned long cmdw;
    unsigned long sccb;
};

struct sccb_header {
    unsigned short length;
};

#define GFP_KERNEL 0
#define GFP_DMA 0
#define PAGE_SIZE 4096
#define EFAULT 1
#define EOPNOTSUPP 2
#define ENOMEM 3
#define EINVAL 4

static inline void *u64_to_uptr(unsigned long val) { return (void *)(uintptr_t)val; }
static inline unsigned long copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline unsigned long copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline void *get_zeroed_page(int flags) { return NULL; }
static inline void free_page(unsigned long addr) {}
static int sclp_ctl_cmdw_supported(unsigned long cmdw) { return 0; }
static int sclp_sync_request(unsigned long cmdw, struct sccb_header *sccb) { return 0; }