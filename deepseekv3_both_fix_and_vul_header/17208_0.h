#include <stdint.h>

#define TRAP_double_fault 8
#define TRAP_nmi 2
#define TRAP_machine_check 18
#define TRAP_debug 1

#define IST_DF 1
#define IST_NMI 2
#define IST_MCE 3
#define IST_DB 4

typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t zero;
} idt_entry_t;

static inline void set_ist(idt_entry_t *entry, uint8_t ist) {
    entry->ist = ist;
}