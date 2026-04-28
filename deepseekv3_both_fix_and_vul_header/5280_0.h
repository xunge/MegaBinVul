#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;
typedef int GF_Err;
typedef struct GF_SceneLoader GF_SceneLoader;

#define GPAC_DISABLE_LOG
#define GF_LOG_PARSER 0
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 0

static int gf_log_tool_level_on(int tool, int level);
static void GF_LOG(u32 level, int tool, const char *fmt);