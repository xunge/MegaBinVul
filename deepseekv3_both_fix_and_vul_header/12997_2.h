#include <stdint.h>

struct device;

struct ufs_hba {
    struct device *dev;
};

struct ufs_mtk_host {
    void *reg_va09;
    uint32_t caps;
};

#define UFS_MTK_CAP_VA09_PWR_CTRL (1 << 0)

struct ufs_mtk_host *ufshcd_get_variant(struct ufs_hba *hba);
void *regulator_get(struct device *dev, const char *id);
void dev_info(struct device *dev, const char *fmt, ...);