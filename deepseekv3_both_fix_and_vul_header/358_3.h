#include <stddef.h>

struct pt_regs;

struct desc_struct {
    unsigned long g:1;
};

short get_segment_selector(struct pt_regs *regs, int seg_reg_idx);
int user_64bit_mode(struct pt_regs *regs);
int v8086_mode(struct pt_regs *regs);
int get_desc_by_ref(struct desc_struct *desc, short sel);
struct desc_struct *get_desc_by_val(short sel);
unsigned long get_desc_limit(struct desc_struct *desc);