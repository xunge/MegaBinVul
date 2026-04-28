#define __init
#include <stdint.h>

extern void setup_cpu_entry_area_ptes(void);
extern void setup_cpu_entry_area(unsigned int cpu);
extern void sync_initial_page_table(void);

#define for_each_possible_cpu(cpu) \
    for ((cpu) = 0; (cpu) < 1; (cpu)++)