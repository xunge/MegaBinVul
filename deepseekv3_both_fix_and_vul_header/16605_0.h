#include <sys/stat.h>

struct cache_def;
#define FL_DIR 1
#define FL_FULLPATH 2

int lstat_cache(struct cache_def *cache, const char *name, int len, int flags, int prefix_len);