#include <ctype.h>
#include <string.h>

#define WebObjects_LEN 10
#define WebObjects_STR "/WebObjects"
#define WEBOBJECTS_STR "/WEBOBJECTS"

typedef enum {
    WOURLOK,
    WOURLInvalidPrefix,
    WOURLInvalidWebObjectsVersion,
    WOURLInvalidApplicationName
} WOURLError;

typedef struct {
    const char *start;
    int length;
} WOURLString;

typedef struct {
    WOURLString prefix;
    WOURLString webObjectsVersion;
    WOURLString applicationName;
} WOURLComponents;

extern const char *cgi_extensions[];
extern const char *app_extensions[];