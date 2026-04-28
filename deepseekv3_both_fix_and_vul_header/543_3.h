#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef uint32_t u32;

struct device {
    // Minimal device structure needed for dev_name()
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

#define QEDI_LOG_WARN 0
#define likely(x) (x)
extern unsigned int qedi_dbg_log;

const char *dev_name(const struct device *dev);
int pr_warn(const char *fmt, ...);