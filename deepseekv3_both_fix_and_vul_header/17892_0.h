#include <string.h>

typedef struct timelib_rel_time {
    int have_special_relative;
    struct {
        int type;
    } special;
} timelib_rel_time;

typedef struct timelib_time {
    timelib_rel_time relative;
} timelib_time;

enum {
    TIMELIB_SPECIAL_WEEKDAY
};

static void do_adjust_special_weekday(timelib_time* time);
static void do_normalize(timelib_time* time);