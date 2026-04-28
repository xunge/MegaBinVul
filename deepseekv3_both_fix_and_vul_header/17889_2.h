#include <stdlib.h>
#include <string.h>

typedef struct timelib_tzinfo timelib_tzinfo;
typedef struct timelib_tzdb timelib_tzdb;
typedef timelib_tzinfo* (*timelib_tz_get_wrapper)(const char *, const timelib_tzdb *);

enum {
    TIMELIB_ZONETYPE_OFFSET,
    TIMELIB_ZONETYPE_ABBR,
    TIMELIB_ZONETYPE_ID
};

struct timelib_time {
    int is_localtime;
    int zone_type;
    int dst;
    timelib_tzinfo *tz_info;
};
typedef struct timelib_time timelib_time;

long timelib_parse_tz_cor(char **ptr);
long timelib_lookup_zone(char **ptr, int *dst, char **tz_abbr, int *found);
void timelib_time_tz_abbr_update(timelib_time *t, char *tz_abbr);