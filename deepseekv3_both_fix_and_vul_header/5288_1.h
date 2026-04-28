#include <stdio.h>
#include <stdarg.h>

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_IO_ERR,
    GF_NOT_SUPPORTED
} GF_Err;

typedef unsigned int u32;
typedef struct GF_MediaExporter GF_MediaExporter;

enum {
    GF_LOG_ERROR,
    GF_LOG_WARNING,
    GF_LOG_AUTHOR
};

#define GF_EXPORT_PROBE_ONLY (1 << 0)
#define GPAC_DISABLE_LOG 0

struct GF_MediaExporter {
    unsigned int flags;
};

int gf_log_tool_level_on(int level, GF_Err e);
void GF_LOG(u32 level, int author, const char *fmt, ...);