#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;
typedef int GF_Err;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_WARNING,
    GF_LOG_PARSER
} GF_LogLevel;

typedef enum {
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Bool;

typedef struct {
    void *sax_parser;
    GF_Err last_error;
} GF_SVG_Parser;

int gf_log_tool_level_on(GF_LogLevel level, GF_Err e);
void GF_LOG(u32 level, GF_LogLevel tool, const char *format, ...);
int gf_xml_sax_get_line(void *sax_parser);
void gf_xml_sax_suspend(void *sax_parser, GF_Bool flag);