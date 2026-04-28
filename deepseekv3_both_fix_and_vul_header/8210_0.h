#include <string.h>
#include <unicode/uloc.h>
#include <unicode/utypes.h>
#include <unicode/ustring.h>

#define LOC_CANONICALIZE_TAG "canonicalize"
#define LOC_LANG_TAG "language"
#define LOC_SCRIPT_TAG "script"
#define LOC_REGION_TAG "region"
#define LOC_VARIANT_TAG "variant"
#define LOC_GRANDFATHERED "grandfathered"

static char* estrdup(const char* str);
static char* estrndup(const char* str, size_t len);
static void efree(void* ptr);
static void* erealloc(void* ptr, size_t size);
static int findOffset(const char* type, const char* loc_name);
static int isIDPrefix(const char* str);
static int getSingletonPos(const char* loc_name);