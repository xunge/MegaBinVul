#include <stdint.h>

typedef uint32_t u32;
struct desc_struct;
extern struct {
    void (*write_ldt_entry)(struct desc_struct *, int, u32, u32);
    void (*write_idt_entry)(struct desc_struct *, int, u32, u32);
} vmi_ops;