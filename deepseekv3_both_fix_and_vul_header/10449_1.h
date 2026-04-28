#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <time.h>

#define HAVE_TM_ZONE 1
#define HAVE_TZNAME 1
#define ABBR_SIZE_MIN 0

typedef struct timezone_t {
    char *abbrs;
    int tz_is_set;
    struct timezone_t *next;
    char *tzname_copy[2];
} *timezone_t;

extern char *tzname[2];

timezone_t tzalloc(const char *name);
void extend_abbrs(char *zone_copy, const char *zone, size_t zone_size);