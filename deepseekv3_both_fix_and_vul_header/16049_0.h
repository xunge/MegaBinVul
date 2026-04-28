#include <stddef.h>
#include <stdio.h>
#include <limits.h>

typedef struct DetectEngineCtx DetectEngineCtx;

#define PATH_MAX _POSIX_PATH_MAX
#define SCLogDebug(...)
#define SCLogNotice(...)
#define SCLogError(...)
#define SC_ERR_INVALID_ARGUMENT 0
#define BUG_ON(cond)

int ConfGetBool(const char *key, int *value);
int PathIsAbsolute(const char *path);
int SCPathContainsTraversal(const char *path);
const char *ConfigGetDataDirectory(void);
size_t strlcpy(char *dst, const char *src, size_t siz);