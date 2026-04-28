#include <stddef.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define EINVAL 22
#define ENOMEM 12
#define GFP_KERNEL 0
#define VPU 1

struct device {
    // minimal device structure definition
};

struct platform_device {
    struct device dev;
};

enum mtk_vcodec_fw_use {
    ENCODER,
    DECODER
};

enum rst_id {
    VPU_RST_ENC,
    VPU_RST_DEC
};

struct mtk_vcodec_dev {
    struct platform_device *plat_dev;
};

struct mtk_vcodec_fw {
    int type;
    void *ops;
    struct platform_device *pdev;
};

void mtk_v4l2_err(const char *msg);
void *devm_kzalloc(struct device *dev, size_t size, int flags);
struct platform_device *vpu_get_plat_device(struct platform_device *pdev);
void vpu_wdt_reg_handler(struct platform_device *pdev, void *handler, void *data, enum rst_id id);
void mtk_vcodec_vpu_reset_handler(void *data);
extern const void *mtk_vcodec_vpu_msg;