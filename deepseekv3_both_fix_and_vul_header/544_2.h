#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef unsigned int u32;

struct device {
    char name[32];
};

struct pci_dev {
    struct device dev;
};

struct qedi_dbg_ctx {
    struct pci_dev *pdev;
    int host_no;
};

struct va_format {
    const char *fmt;
    va_list *va;
};

#define likely(x) (x)
#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
static inline const char *dev_name(const struct device *dev) {
    return dev->name;
}