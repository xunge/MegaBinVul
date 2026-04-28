#include <stddef.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define EINVAL 22
#define ENODEV 19
#define EPROBE_DEFER 517

struct device_node;

struct device {
    struct device_node *of_node;
};

struct platform_device {
    struct device dev;
};

struct qmp;

void *of_parse_phandle(struct device_node *node, const char *phandle, int index);
struct platform_device *of_find_device_by_node(struct device_node *node);
void of_node_put(struct device_node *node);
void *platform_get_drvdata(struct platform_device *pdev);
void put_device(struct device *dev);