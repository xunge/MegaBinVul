#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>

#define _VPF_down 0
#define PSR_MODE_MASK 0x1F
#define PSR_MODE_USR 0x10
#define PSR_MODE_SYS 0x1F
#define PSR_MODE_FIQ 0x11
#define PSR_MODE_IRQ 0x12
#define PSR_MODE_SVC 0x13
#define PSR_MODE_ABT 0x17
#define PSR_MODE_UND 0x1B
#define PSR_MODE_HYP 0x1A
#define PSR_MODE_MON 0x16
#define PSR_MODE_EL0t 0x00
#define PSR_MODE_EL1t 0x04
#define PSR_MODE_EL1h 0x05
#define PSR_MODE_EL2t 0x08
#define PSR_MODE_EL2h 0x09
#define PSR_MODE_EL3t 0x0C
#define PSR_MODE_EL3h 0x0D
#define CONFIG_ARM_64 1
#define GV2M_READ 0
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define debug_stack_lines 10
#define stack_words_per_line 4

typedef uint64_t vaddr_t;
typedef uint64_t paddr_t;

struct vcpu {
    unsigned long pause_flags;
};

struct cpu_user_regs {
    uint32_t cpsr;
    vaddr_t sp_fiq;
    vaddr_t sp_irq;
    vaddr_t sp_svc;
    vaddr_t sp_abt;
    vaddr_t sp_und;
    vaddr_t sp_el0;
    vaddr_t sp_el1;
};

#define BUG() do { printf("BUG\n"); } while (0)
#define printk printf
#define test_bit(bit, addr) ((*(addr)) & (1UL << (bit)))
#define gvirt_to_maddr(vaddr, paddr, ...) (0)
#define map_domain_page(page) ((void *)(page))
#define unmap_domain_page(ptr) do {} while (0)
#define _p(addr) ((void *)(addr))
#define PRIvaddr "lx"