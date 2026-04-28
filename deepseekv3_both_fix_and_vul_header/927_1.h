#include <stddef.h>

#define _SEGMENT_DPL 0x00006000
#define FIRST_RESERVED_GDT_BYTE 0xff0

struct vcpu {
    struct {
        struct {
            unsigned int gdt_ents;
            unsigned int ldt_ents;
        } pv;
    } arch;
};

typedef struct {
    unsigned int a;
    unsigned int b;
} seg_desc_t;

static const seg_desc_t *gdt_ldt_desc_ptr(unsigned int gate_sel);
static int is_pv_32bit_vcpu(const struct vcpu *v);
static int __get_user(seg_desc_t dest, const seg_desc_t *src);