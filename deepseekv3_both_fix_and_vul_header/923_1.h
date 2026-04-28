#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define __init
#define ENODEV 19

extern bool force_iommu;
extern bool iommu_intremap;
extern bool iommu_hwdom_strict;
extern bool iommu_hwdom_passthrough;
extern bool iommu_enable;
extern bool iommu_enabled;
extern int iommu_intpost;
extern int iommu_snoop;
extern struct domain *dom_io;
extern struct tasklet_struct iommu_pt_cleanup_tasklet;

#define XEN_DOMCTL_CDF_iommu (1 << 0)

typedef bool bool_t;

struct domain {
    unsigned int options;
};

struct tasklet_struct {
    void (*func)(unsigned long);
    unsigned long data;
};

void panic(const char *fmt, ...);
void printk(const char *fmt, ...);
int iommu_hardware_setup(void);
int iommu_domain_init(struct domain *d, int flags);
void iommu_free_pagetables(unsigned long data);
void tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data);