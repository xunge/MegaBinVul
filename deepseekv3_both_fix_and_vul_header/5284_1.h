#include <stdio.h>
#include <stdarg.h>

typedef struct {
    int current_frame;
} SWFReader;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_WARNING,
    GF_LOG_PARSER
} GF_LogLevel;

typedef enum {
    GF_OK,
    GF_ERR
} GF_Err;

int gf_log_tool_level_on(GF_LogLevel level, GF_Err e);
void GF_LOG(unsigned int level, GF_LogLevel tool, const char *format, ...);

#ifndef GPAC_DISABLE_LOG
#define GPAC_DISABLE_LOG
#endif

typedef unsigned int u32;