struct device;

#define Z_OOPS(x)
#define Z_SYSCALL_DRIVER_GPIO(dev, func)

int z_impl_gpio_get_pending_int(struct device *dev);