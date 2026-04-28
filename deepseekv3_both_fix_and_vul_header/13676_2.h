#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef uint32_t u32;

#define AMD_IP_BLOCK_TYPE_ACP 0
#define ACP_DEVS 4
#define ACP_DMA_REGS_END 0x5289
#define ACP_I2S_PLAY_REGS_START 0
#define ACP_I2S_PLAY_REGS_END 0
#define ACP_I2S_CAP_REGS_START 0
#define ACP_I2S_CAP_REGS_END 0
#define ACP_BT_PLAY_REGS_START 0
#define ACP_BT_PLAY_REGS_END 0
#define ACP_I2S_COMP1_PLAY_REG_OFFSET 0
#define ACP_I2S_COMP2_PLAY_REG_OFFSET 0
#define ACP_I2S_COMP1_CAP_REG_OFFSET 0
#define ACP_I2S_COMP2_CAP_REG_OFFSET 0
#define ACP_BT_COMP1_REG_OFFSET 0
#define ACP_BT_COMP2_REG_OFFSET 0
#define ACP_SOFT_RESET_DONE_TIME_OUT_VALUE 100
#define ACP_CLOCK_EN_TIME_OUT_VALUE 100

#define DW_I2S_QUIRK_COMP_REG_OFFSET (1 << 0)
#define DW_I2S_QUIRK_COMP_PARAM1 (1 << 1)
#define DW_I2S_QUIRK_16BIT_IDX_OVERRIDE (1 << 2)

#define DWC_I2S_PLAY (1 << 0)
#define DWC_I2S_RECORD (1 << 1)
#define SNDRV_PCM_RATE_8000_96000 0

#define mmACP_SOFT_RESET 0
#define mmACP_CONTROL 0
#define mmACP_STATUS 0
#define ACP_SOFT_RESET__SoftResetAud_MASK (1 << 0)
#define ACP_SOFT_RESET__SoftResetAudDone_MASK (1 << 1)
#define ACP_CONTROL__ClkEn_MASK (1 << 0)

#define CHIP_STONEY 0

#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12
#define EINVAL 22
#define ETIMEDOUT 110
#define IORESOURCE_MEM 0
#define IORESOURCE_IRQ 0

struct device {
    const char *name;
};

struct mfd_cell {
    const char *name;
    int num_resources;
    struct resource *resources;
    void *platform_data;
    size_t pdata_size;
};

struct resource {
    const char *name;
    unsigned long start;
    unsigned long end;
    unsigned long flags;
};

struct i2s_platform_data {
    unsigned int quirks;
    unsigned int cap;
    unsigned int snd_rates;
    unsigned int i2s_reg_comp1;
    unsigned int i2s_reg_comp2;
};

struct generic_pm_domain {
    const char *name;
    int (*power_off)(struct generic_pm_domain *);
    int (*power_on)(struct generic_pm_domain *);
};

struct acp_pm_domain {
    struct generic_pm_domain gpd;
    void *adev;
};

struct amdgpu_acp {
    void *cgs_device;
    struct acp_pm_domain *acp_genpd;
    struct mfd_cell *acp_cell;
    struct resource *acp_res;
    struct device *parent;
};

struct amdgpu_device {
    struct amdgpu_acp acp;
    void *rmmio_base;
    unsigned long rmmio_size;
    unsigned int asic_type;
    struct {
        struct device *dev;
    } *pdev;
};

struct amdgpu_ip_block_version {
    int major;
    int minor;
};

struct amdgpu_ip_block {
    struct amdgpu_ip_block_version *version;
};

static inline int amdgpu_irq_create_mapping(struct amdgpu_device *adev, int irq) { return 0; }
static inline int amd_acp_hw_init(void *cgs_device, int major, int minor) { return 0; }
static inline const struct amdgpu_ip_block *amdgpu_device_ip_get_ip_block(struct amdgpu_device *adev, int type) { return NULL; }
static inline int amdgpu_dpm_set_powergating_by_smu(struct amdgpu_device *adev, int type, bool enable) { return 0; }
static inline int pm_genpd_init(struct generic_pm_domain *gpd, void *null, bool b) { return 0; }
static inline int pm_genpd_add_device(struct generic_pm_domain *gpd, struct device *dev) { return 0; }
static inline int mfd_add_hotplug_devices(struct device *parent, struct mfd_cell *cells, int count) { return 0; }
static inline struct device *get_mfd_cell_dev(const char *name, int idx) { return NULL; }
static inline u32 cgs_read_register(void *cgs_device, u32 reg) { return 0; }
static inline void cgs_write_register(void *cgs_device, u32 reg, u32 val) {}
static inline void *kzalloc(size_t size, int flags) { return malloc(size); }
static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void udelay(unsigned long usecs) {}

static int acp_poweroff(struct generic_pm_domain *gpd) { return 0; }
static int acp_poweron(struct generic_pm_domain *gpd) { return 0; }