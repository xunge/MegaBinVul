#include <stdio.h>
#include <stdarg.h>

typedef int GF_Err;
typedef unsigned int u32;

#define GF_LOG_PARSER 0
#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2

struct GF_XMLSAXParser;
typedef struct GF_XMTParser {
    struct GF_XMLSAXParser *sax_parser;
    GF_Err last_error;
} GF_XMTParser;

#ifndef GPAC_DISABLE_LOG
int gf_log_tool_level_on(int log_tool, GF_Err level);
void GF_LOG(u32 level, int log_tool, const char *format, ...);
int gf_xml_sax_get_line(struct GF_XMLSAXParser *sax_parser);
#endif