#include <stddef.h>
#include <string.h>

#define MAX_NR_ZONES 3
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define MAX_DMA_ADDRESS 0xFFFFFFFF
#define PFN_DOWN(x) ((x) >> PAGE_SHIFT)
#define __pa(x) ((unsigned long)(x))
#define _ASCE_TYPE_REGION2 0x20000000
#define _ASCE_TABLE_LENGTH 0x0F000000
#define _REGION2_ENTRY_EMPTY 0x400UL
#define _SEGMENT_ENTRY_EMPTY 0x400UL
#define __init

enum zone_type {
    ZONE_DMA,
    ZONE_NORMAL,
    ZONE_MOVABLE,
    __MAX_NR_ZONES
};

struct mm_struct {
    unsigned long *pgd;
};

struct lowcore {
    unsigned long kernel_asce;
};

extern struct mm_struct init_mm;
extern struct lowcore S390_lowcore;
extern unsigned long max_low_pfn;
extern unsigned long *swapper_pg_dir;

void clear_table(unsigned long *table, unsigned long val, unsigned long size);
void vmem_map_init(void);
void setup_ro_region(void);
void free_area_init_nodes(unsigned long *max_zone_pfns);
void __ctl_load(unsigned long asce, int cr1, int cr2);
void __raw_local_irq_ssm(unsigned long mask);