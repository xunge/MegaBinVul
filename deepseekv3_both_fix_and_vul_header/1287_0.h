#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GLIB_CHARSETALIAS_DIR ""
#define ISSLASH(c) ((c) == '/')
#define DIRECTORY_SEPARATOR '/'

static const char *charset_aliases = NULL;

const char *relocate(const char *path);