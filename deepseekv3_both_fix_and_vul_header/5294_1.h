#include <stdio.h>
#include <stdarg.h>

typedef unsigned int u32;
typedef struct GF_SceneLoader GF_SceneLoader;
typedef int GF_Err;
typedef enum GF_LogLevel GF_LogLevel;
#define GF_LOG_PARSER 0
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 0
#define GPAC_DISABLE_LOG 0

int gf_log_tool_level_on(int tool, GF_LogLevel level);
void GF_LOG(u32 level, int tool, const char* fmt);