#include <stdint.h>
#include <errno.h>
#include <stdio.h>

struct xen_domctl {
    int cmd;
    union {
        struct {
            int dev;
            int flags;
            union {
                struct {
                    const char *path;
                    int size;
                } dt;
            } u;
        } assign_device;
    } u;
};

#define XEN_DOMCTL_assign_device 0
#define XEN_DOMCTL_test_assign_device 1
#define XEN_DOMCTL_deassign_device 2
#define XEN_DOMCTL_DEV_DT 0

#define XENLOG_G_ERR ""

struct domain {
    int is_dying;
    unsigned int domain_id;
};

struct dt_device_node;
extern struct domain *dom_io;

#define XSM_HOOK 0
#define ASSERT(x) (void)(x)

int dt_find_node_by_gpath(const char *path, int size, struct dt_device_node **dev);
char *dt_node_full_name(struct dt_device_node *dev);
int xsm_assign_dtdevice(int hook, struct domain *d, char *name);
int xsm_deassign_dtdevice(int hook, struct domain *d, char *name);
int iommu_dt_device_is_assigned(struct dt_device_node *dev);
int iommu_add_dt_device(struct dt_device_node *dev);
int iommu_assign_dt_device(struct domain *d, struct dt_device_node *dev);
int iommu_deassign_dt_device(struct domain *d, struct dt_device_node *dev);
void printk(const char *fmt, ...);

#define XEN_GUEST_HANDLE_PARAM(type) void*
typedef void xen_domctl_t;