#include <stdio.h>
#include <stdarg.h>

typedef enum {
    GF_LOG_LEVEL_ERROR,
    GF_LOG_LEVEL_WARNING,
    GF_LOG_LEVEL_INFO,
    GF_LOG_LEVEL_DEBUG
} GF_LOG_Level;

typedef enum {
    GF_LOG_TOOL_CORE,
    GF_LOG_TOOL_CONTAINER,
    GF_LOG_TOOL_CODING,
    GF_LOG_TOOL_NETWORK
} GF_LOG_Tool;

typedef struct COsmo4AppView {
    void *m_mx;
    FILE *m_Logs;
    void (*MessageBox)(const char*, const char*);
} COsmo4AppView;

void gf_mx_p(void *mx);
void gf_mx_v(void *mx);