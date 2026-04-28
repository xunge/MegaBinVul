#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TASK_SIZE_MAX (~0UL)
#define __stringify(x) #x

typedef uint8_t u8;

struct pt_regs {
    unsigned long ip;
};

bool user_mode(struct pt_regs *regs);
bool __chk_range_not_ok(unsigned long addr, size_t size, unsigned long limit);
bool probe_kernel_read(void *dst, const void *src, size_t size);
int printk(const char *fmt, ...);