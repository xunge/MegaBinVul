#include <stdlib.h>
#include <stdint.h>

#define CONFIG_X86_32 0
#define PMD_SIZE 0
#define PMD_MASK 0
#define TASK_SIZE_MAX 0
#define PTRS_PER_PTE 0
#define PAGE_SHIFT 0
#define PAGE_ALIGN(addr) ((addr) & ~(PAGE_SIZE-1))
#define PAGE_SIZE 4096

static unsigned int get_random_int(void) { return rand(); }
static unsigned long align_vdso_addr(unsigned long addr) { return addr; }