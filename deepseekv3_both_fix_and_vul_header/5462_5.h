#include <stdint.h>
#include <stdio.h>

#define SZ_64K  0x00010000
#define SZ_128K 0x00020000
#define XENLOG_G_WARNING 0
#define XENLOG_WARNING 0
#define PRIpaddr "lx"

struct vcpu {
    struct domain *domain;
    const char *name;
};

struct domain {
    struct {
        struct {
            unsigned long rdist_stride;
        } vgic;
    } arch;
};

typedef struct {
    unsigned long gpa;
} mmio_info_t;

typedef int perfc_t;
extern perfc_t vgicr_writes;

void perfc_incr(perfc_t counter);
int __vgic_v3_rdistr_rd_mmio_write(struct vcpu *v, mmio_info_t *info, uint32_t offset);
int vgic_v3_rdistr_sgi_mmio_write(struct vcpu *v, mmio_info_t *info, uint32_t offset);

#define printk(level, fmt, ...) printf(fmt, __VA_ARGS__)
#define gdprintk(level, fmt, ...) printf(fmt, __VA_ARGS__)