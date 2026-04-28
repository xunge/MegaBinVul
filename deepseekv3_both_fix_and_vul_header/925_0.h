#include <stdbool.h>

#define _SEGMENT_L 0x200000
#define _SEGMENT_G 0x800000

typedef union {
    struct {
        unsigned int a;
        unsigned int b;
    };
    unsigned long raw[1];
} seg_desc_t;

struct vcpu {
    struct {
        struct {
            unsigned int ldt_ents;
        } pv;
    } arch;
};

extern unsigned long *gdt_ldt_desc_ptr(unsigned int sel);
extern void BUG_ON(bool condition);