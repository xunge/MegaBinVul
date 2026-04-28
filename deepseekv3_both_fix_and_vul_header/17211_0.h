#include <stddef.h>

#define PAGE_SIZE 4096
#define STACK_SIZE 8192
#define ROUNDUP(x, y) (((x) + (y) - 1) & ~((y) - 1))

struct cpu_user_regs {
    unsigned long es;
};

struct cpu_info {
    unsigned long data;
};

unsigned long get_stack_page(unsigned long sp);