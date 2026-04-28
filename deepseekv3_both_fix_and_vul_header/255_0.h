#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define WSZ 32

typedef struct RParse RParse;

static void replace(int nw, const char **wa, char *str);
static void r_str_trim(char *buf);