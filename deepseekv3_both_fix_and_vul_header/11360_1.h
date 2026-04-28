#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

extern unsigned long io_tlb_nslabs;
extern unsigned int IO_TLB_SHIFT;
extern bool no_iotlb_memory;
extern uintptr_t io_tlb_start;
extern uintptr_t io_tlb_end;

#define KERN_INFO ""
#define pr_warn(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define phys_to_virt(addr) ((void*)(addr))