#include <string.h>

struct timelib_time;
struct timelib_error_container {
    int error_count;
};

#define DATE_TIMEZONEDB 0

struct timelib_time *timelib_strtotime(char *string, size_t len, struct timelib_error_container **error, int mode, ...);
void timelib_error_container_dtor(struct timelib_error_container *error);
void timelib_update_ts(struct timelib_time *t, struct timelib_time *now);
long timelib_date_to_int(struct timelib_time *t, int *error);
void timelib_time_dtor(struct timelib_time *t);

typedef struct timelib_time timelib_time;
typedef struct timelib_error_container timelib_error_container;

extern void *php_date_parse_tzfile_wrapper;