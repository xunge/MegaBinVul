#include <stdbool.h>
#include <stddef.h>
#include <libintl.h>

struct ttfinfo {
    bool bad_cff;
};

extern int nStdStrings;
extern const char *cffnames[];
extern void LogError(const char *fmt, ...);