#include <stddef.h>
#include <stdbool.h>

#define EFBIG 1
#define EFAULT 2
#define EPERM 3

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12

typedef unsigned long phys_addr_t;
typedef long ssize_t;
typedef long long loff_t;

struct file {
    // minimal stub
};
typedef struct file file;

#define __user

static bool valid_phys_addr_range(phys_addr_t p, size_t count);
static size_t size_inside_page(phys_addr_t p, size_t count);
static bool range_is_allowed(unsigned long pfn, size_t count);
static void *xlate_dev_mem_ptr(phys_addr_t p);
static void unxlate_dev_mem_ptr(phys_addr_t p, void *ptr);
static unsigned long copy_from_user(void *to, const void __user *from, unsigned long n);