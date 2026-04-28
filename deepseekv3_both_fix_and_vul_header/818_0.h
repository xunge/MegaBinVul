#include <stdint.h>

#define X86_CR4_PGE    (1UL << 7)
#define X86_CR4_PCIDE  (1UL << 17)
#define X86_CR3_NOFLUSH (1UL << 63)

typedef uint32_t u32;

unsigned long read_cr3(void);
unsigned long read_cr4(void);
void write_cr3(unsigned long);
void write_cr4(unsigned long);
void local_irq_save(unsigned long);
void local_irq_restore(unsigned long);
u32 pre_flush(void);
void post_flush(u32);
void invpcid_flush_all_nonglobals(void);
void invpcid_flush_single_context(unsigned long);
unsigned long cr3_pcid(unsigned long);
int use_invpcid;