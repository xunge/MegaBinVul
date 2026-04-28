#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PATH_SEP '/'
#define CONTROL(cond) if (!(cond)) { free(outDirBuffer); return NULL; }