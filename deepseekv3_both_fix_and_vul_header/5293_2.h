#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;

typedef enum {
    GF_OK = 0
} GF_Err;

typedef enum {
    GF_LOG_PARSER,
    GF_LOG_ERROR, 
    GF_LOG_WARNING
} GF_LogLevel;

typedef struct GF_BTParser {
    int line;
    GF_Err last_error;
} GF_BTParser;

int gf_log_tool_level_on(GF_LogLevel level, GF_Err e);
void GF_LOG(u32 level, GF_LogLevel tool, const char *format, ...);