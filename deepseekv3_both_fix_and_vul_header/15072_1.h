#include <stdio.h>

struct unwind_frame_info {
    unsigned long ip;
};

#define KERN_CRIT ""
#define RFMT "lx"
#define printk printf
#define unwind_once(info) (0)
#define __kernel_text_address(addr) (1)
#define print_symbol(fmt, addr) printf(fmt, "symbol")
#define CONFIG_KALLSYMS