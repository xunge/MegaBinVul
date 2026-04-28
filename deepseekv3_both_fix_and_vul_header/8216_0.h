#include <stdlib.h>
#include <string.h>

#define LOC_GRANDFATHERED_LEN 0
#define LOC_PREFERRED_GRANDFATHERED_LEN 0
static const char* LOC_GRANDFATHERED[LOC_GRANDFATHERED_LEN];
static const char* LOC_PREFERRED_GRANDFATHERED[LOC_PREFERRED_GRANDFATHERED_LEN];

static int findOffset(const char* const* list, const char* str);
static char* estrdup(const char* s);