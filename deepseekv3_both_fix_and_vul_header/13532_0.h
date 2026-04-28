#include <stdlib.h>
#include <string.h>

typedef struct dictionary dictionary;
#define INI_INVALID_KEY NULL

const char *iniparser_getstring(const dictionary *d, const char *key, const char *def);