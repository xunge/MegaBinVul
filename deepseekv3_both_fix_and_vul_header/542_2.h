#include <stdarg.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;

struct qedi_dbg_ctx {
    void *pdev;
    int host_no;
};

struct va_format {
    const char *fmt;
    va_list *va;
};

#define QEDI_LOG_NOTICE 0
#define qedi_dbg_log 0
#define likely(x) (x)
#define pr_notice(fmt, ...)