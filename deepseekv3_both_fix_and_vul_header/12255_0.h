#include <limits.h>
#include <string.h>

typedef struct {
    char *name;
    char **lines;
    unsigned int nlines;
} XpmExtension;