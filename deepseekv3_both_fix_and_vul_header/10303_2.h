#include <sys/types.h>
#include <stddef.h>

typedef unsigned long phys_addr_t;
typedef long ssize_t;

#define __user
#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define EFAULT 14
#define EPERM 1

struct file {
    loff_t f_pos;
};

extern int valid_phys_addr_range(phys_addr_t p, size_t count);
extern size_t size_inside_page(phys_addr_t p, size_t count);
extern int range_is_allowed(unsigned long pfn, size_t count);
extern void *xlate_dev_mem_ptr(phys_addr_t p);
extern void unxlate_dev_mem_ptr(phys_addr_t p, void *ptr);
extern unsigned long copy_to_user(void __user *to, const void *from, unsigned long n);
extern int clear_user(void __user *to, unsigned long n);