#include <stdbool.h>
#include <stddef.h>

#define CPU_ENTRY_AREA_BASE 0
#define CPU_ENTRY_AREA_MAP_SIZE 0
#define CPU_ENTRY_AREA_TOTAL_SIZE 0
#define GDT_SIZE 0
#define CONFIG_SMP 0
#define nr_cpu_ids 0
#define for_each_possible_cpu(cpu) for (cpu = 0; cpu < 0; cpu++)

extern unsigned long __per_cpu_offset[];
extern unsigned long pcpu_unit_offsets;
extern void *get_cpu_gdt_rw(int cpu);
extern struct tss_struct cpu_tss_rw;
extern struct tlb_state cpu_tlbstate;
extern unsigned long cpu_dr7;

struct tss_struct {};
struct tlb_state {};

#define per_cpu(var, cpu) (var)

static inline bool within_area(unsigned long addr, unsigned long end,
                             unsigned long base, unsigned long size) {
    return false;
}