#include <stddef.h>

#define PAGE_SIZE 4096
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

struct cpu_entry_area {
    char _dummy[PAGE_SIZE];
};

typedef struct cpu_entry_area cpu_entry_area;

extern unsigned long CPU_ENTRY_AREA_PER_CPU;
extern unsigned long CPU_ENTRY_AREA_SIZE;