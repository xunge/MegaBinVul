#include <stdint.h>
#include <stdio.h>

#define GICD_SGI_TARGET_LIST_MASK   0x0f
#define GICD_SGI_TARGET_LIST_SHIFT  24
#define GICD_SGI_INTID_MASK         0x0f
#define GICD_SGI_TARGET_MASK        0xffff
#define GICD_SGI_TARGET_SHIFT       0
#define GICD_SGI_TARGET_LIST_VAL    0
#define GICD_SGI_TARGET_OTHERS_VAL  1
#define GICD_SGI_TARGET_SELF_VAL    2
#define XENLOG_G_DEBUG              0
#define PRIregister                 "lx"
#define BUG()                      do { while(1); } while(0)

enum gic_sgi_mode {
    SGI_TARGET_LIST,
    SGI_TARGET_OTHERS,
    SGI_TARGET_SELF
};

struct vcpu;
typedef unsigned long register_t;
int vgic_to_sgi(struct vcpu *v, register_t sgir, enum gic_sgi_mode sgi_mode, int virq, unsigned long vcpu_mask);
int printk(int level, const char *format, ...);

#define printk(level, fmt, ...) printf(fmt, ##__VA_ARGS__)