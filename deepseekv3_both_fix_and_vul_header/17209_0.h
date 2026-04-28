#include <stdint.h>

#define IST_NONE 0

enum {
    TRAP_double_fault,
    TRAP_nmi,
    TRAP_machine_check,
    TRAP_debug
};

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