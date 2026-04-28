#include <string.h>

#define __init
#define CONFIG_KEXEC
#define EINVAL 22

extern int iommu_enable;
extern int force_iommu;
extern int iommu_quarantine;
extern int iommu_igfx;
extern int iommu_verbose;
extern int iommu_snoop;
extern int iommu_qinval;
extern int iommu_intremap;
extern int iommu_intpost;
extern int iommu_crash_disable;
extern int iommu_debug;
extern int amd_iommu_perdev_intremap;
extern int iommu_hwdom_passthrough;
extern int iommu_hwdom_strict;
extern int iommu_hap_pt_share;

extern int parse_bool(const char *s, const char *e);
extern int parse_boolean(const char *name, const char *s, const char *e);