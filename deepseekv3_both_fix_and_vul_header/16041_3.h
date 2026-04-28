#include <stddef.h>

struct device;

struct platform_device {
    struct device *dev;
};

struct rkvdec_dev {
    void *watchdog_work;
};

void *platform_get_drvdata(struct platform_device *pdev);
void cancel_delayed_work_sync(void *work);
void rkvdec_v4l2_cleanup(struct rkvdec_dev *rkvdec);
void pm_runtime_disable(struct device *dev);
void pm_runtime_dont_use_autosuspend(struct device *dev);