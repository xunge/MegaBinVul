#include <stddef.h>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

typedef struct {
    unsigned int a, b;
} ldt_desc;

extern unsigned int smp_processor_id(void);
extern void set_tssldt_descriptor(ldt_desc *desc, unsigned long addr, unsigned type, unsigned size);
extern void *get_cpu_gdt_table(unsigned int cpu);
extern void write_gdt_entry(void *gdt, unsigned int entry, void *desc, unsigned int type);

#define GDT_ENTRY_LDT 12
#define DESC_LDT 2
#define LDT_ENTRY_SIZE 8