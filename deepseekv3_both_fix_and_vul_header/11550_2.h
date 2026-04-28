#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

typedef enum {
    UDISKS_LOG_LEVEL_ERROR,
    UDISKS_LOG_LEVEL_CRITICAL,
    UDISKS_LOG_LEVEL_WARNING,
    UDISKS_LOG_LEVEL_MESSAGE,
    UDISKS_LOG_LEVEL_INFO,
    UDISKS_LOG_LEVEL_DEBUG
} UDisksLogLevel;

typedef int gint;
typedef char gchar;

char* g_strdup_vprintf(const char* format, va_list args);
void g_free(void* ptr);
void g_log(const char* domain, UDisksLogLevel level, const char* format, ...);
void g_log_structured(const char* domain, int level_flags, ...);

#define GLIB_CHECK_VERSION(major, minor, micro) 0