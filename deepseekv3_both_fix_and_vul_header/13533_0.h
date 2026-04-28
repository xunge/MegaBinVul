#include <string.h>

typedef struct dictionary dictionary;
#define INI_INVALID_KEY ((char*)-1)

const char * iniparser_getstring(const dictionary * d, const char * key, const char * def);