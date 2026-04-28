#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;
typedef int GF_Err;

typedef struct {
    void *sax_parser;
    GF_Err last_error;
} GF_XBL_Parser;

#define GPAC_DISABLE_LOG
#define GF_LOG_PARSER 0
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 0

static int gf_log_tool_level_on(int log_tool, int level);
static int gf_xml_sax_get_line(void *sax_parser);
void GF_LOG(u32 level, u32 tool, const char *fmt, ...);