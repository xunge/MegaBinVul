#include <stdlib.h>
#include <string.h>

struct link_map;

static char *local_strdup(const char *s);
#define DL_DST_COUNT(s, a) 0
#define DL_DST_REQUIRED(l, s, len, cnt) 0
#define DL_DST_SUBSTITUTE(l, s, res, a) NULL