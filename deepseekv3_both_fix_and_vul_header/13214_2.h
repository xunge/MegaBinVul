#include <stdint.h>

struct platform_device {
    void *dev_data;
};

struct work_struct {
    uint32_t dummy;
};

struct hwmon_device {
    uint32_t dummy; 
};

struct mbox_chan {
    uint32_t dummy;
};

struct kfifo {
    uint32_t dummy;
};

struct xgene_hwmon_dev {
    struct work_struct workq;
    struct hwmon_device *hwmon_dev;
    struct kfifo async_msg_fifo;
    struct mbox_chan *mbox_chan;
    struct mbox_chan *pcc_chan;
};

extern int acpi_disabled;
void *platform_get_drvdata(struct platform_device *pdev);
void cancel_work_sync(struct work_struct *work);
void hwmon_device_unregister(struct hwmon_device *dev);
void kfifo_free(struct kfifo *fifo);
void mbox_free_channel(struct mbox_chan *chan);
void pcc_mbox_free_channel(struct mbox_chan *chan);