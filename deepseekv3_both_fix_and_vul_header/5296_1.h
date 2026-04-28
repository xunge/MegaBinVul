#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;
typedef int GF_Err;
typedef struct GF_MediaImporter GF_MediaImporter;

#define GPAC_DISABLE_LOG
#define GF_LOG_AUTHOR 0
#define GF_LOG_WARNING 1
#define GF_LOG_INFO 2

int gf_log_tool_level_on(int author, int level);
void GF_LOG(u32 level, int author, const char *fmt, ...);