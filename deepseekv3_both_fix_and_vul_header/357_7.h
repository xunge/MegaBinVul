#include <stddef.h>
#include <stdint.h>

#define BIT(nr) (1UL << (nr))
#define INAT_SEG_REG_CS 0
#define INSN_CODE_SEG_PARAMS(a, b) ((a) | ((b) << 4))
#define EINVAL 22

struct pt_regs;
struct desc_struct {
    unsigned long type;
    unsigned long l;
    unsigned long d;
};

int v8086_mode(struct pt_regs *regs);
int get_segment_selector(struct pt_regs *regs, int seg_reg);
int get_desc_by_ref(struct desc_struct *desc, short sel);
struct desc_struct *get_desc_by_sel(short sel);