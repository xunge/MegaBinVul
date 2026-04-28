#include <stddef.h>

struct platform_device {
    void *dev_data;
};

struct gpio_chip {
    // minimal required fields
    int base;
    unsigned ngpio;
};

struct pinctrl_dev {
    // minimal required fields
    void *driver_data;
};

struct amd_gpio {
    struct gpio_chip gc;
    struct pinctrl_dev *pctrl;
};

// Declare functions to avoid implicit declaration warnings
void *platform_get_drvdata(struct platform_device *pdev);
void gpiochip_remove(struct gpio_chip *gc);
void pinctrl_unregister(struct pinctrl_dev *pdev);