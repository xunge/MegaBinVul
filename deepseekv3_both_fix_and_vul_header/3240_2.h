#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

typedef int64_t loff_t;
typedef long ssize_t;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

struct file {
    void *private_data;
};

struct debug_data {
    char *name;
    void *addr;
    size_t size;
};

extern int num_of_items;
#define GFP_KERNEL 0
#define __user

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base);
int copy_from_user(void *to, const void *from, unsigned long n);