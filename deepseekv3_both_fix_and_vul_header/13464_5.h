#include <stddef.h>

struct device;
struct i2c_client;

struct bq24190_dev_info {
    struct device *dev;
    void *input_current_limit_work;
    void *battery;
    void *charger;
};

void *i2c_get_clientdata(struct i2c_client *client);
void cancel_delayed_work_sync(void *work);
int pm_runtime_resume_and_get(struct device *dev);
void dev_warn(struct device *dev, const char *fmt, ...);
void bq24190_register_reset(struct bq24190_dev_info *bdi);
void power_supply_unregister(void *psy);
void pm_runtime_put_sync(struct device *dev);
void pm_runtime_dont_use_autosuspend(struct device *dev);
void pm_runtime_disable(struct device *dev);