#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;

struct qedi_dbg_ctx {
    struct {
        struct {
            char *dev;
        } dev;
    } *pdev;
    u32 host_no;
};

struct va_format {
    const char *fmt;
    va_list *va;
};

extern u32 qedi_dbg_log;

#define likely(x) (x)
#define pr_info(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_name(dev) "dev"