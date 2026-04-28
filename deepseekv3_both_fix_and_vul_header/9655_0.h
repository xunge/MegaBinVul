#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define DB_ENVIRONMENT "GIT_DIR"
#define PATH_MAX 4096

static int validate_headref(const char *path);