#define CONFIG_X86_32 1
#define CPU_ENTRY_AREA_PAGES 5
#define CPU_ENTRY_AREA_MAP_SIZE (6*4096)
#define CPU_ENTRY_AREA_TOTAL_SIZE (6*4096)
#define CPU_ENTRY_AREA_BASE 0xFFFFE000
#define PMD_MASK (~((1<<21)-1))
#define PMD_SIZE (1<<21)
#define PAGE_SIZE 4096

#define __init 
#define BUILD_BUG_ON(cond) ((void)0)
#define BUG_ON(cond) ((void)0)

static void populate_extra_pte(unsigned long addr) {}