#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define __init
#define ENODEV 19

typedef bool bool_t;

extern int force_iommu;
extern bool_t iommu_intremap;
extern bool_t iommu_hwdom_strict;
extern bool_t iommu_hwdom_passthrough;
extern bool_t iommu_enable;
extern bool_t iommu_enabled;
extern bool_t iommu_intpost;
extern bool_t iommu_snoop;
extern struct domain *dom_io;
extern struct tasklet_struct iommu_pt_cleanup_tasklet;

void panic(const char *fmt, ...);
int printk(const char *fmt, ...);
int iommu_hardware_setup(void);
int iommu_domain_init(struct domain *d, int flags);
void iommu_free_pagetables(unsigned long data);
void tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data);

#define XEN_DOMCTL_CDF_iommu (1U << 0)

struct domain {
    unsigned int options;
};

struct tasklet_struct {
    void (*func)(unsigned long);
    unsigned long data;
};