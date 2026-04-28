struct platform_device;
struct pinctrl_dev;

struct amd_gpio {
    void *gc;  // 替换为不完整类型指针
    struct pinctrl_dev *pctrl;
};

void* platform_get_drvdata(struct platform_device *pdev);
void gpiochip_remove(void *gc);  // 修改参数类型
void pinctrl_unregister(struct pinctrl_dev *pdev);