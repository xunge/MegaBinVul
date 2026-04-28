#include <stddef.h>

typedef struct timelib_rel_time {
    int y, m, d, h, i, s;
    int weekday, weekday_behavior;
    int first_last_day_of;
    int have_weekday_relative, have_special_relative;
    struct {
        int type;
    } special;
} timelib_rel_time;

typedef struct timelib_time {
    int y, m, d, h, i, s;
    timelib_rel_time relative;
} timelib_time;

static void do_normalize(timelib_time* time);

#define TIMELIB_SPECIAL_DAY_OF_WEEK_IN_MONTH 1
#define TIMELIB_SPECIAL_LAST_DAY_OF_WEEK_IN_MONTH 2