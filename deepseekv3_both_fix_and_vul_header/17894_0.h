#include <stddef.h>

typedef struct {
    int have_weekday_relative;
    int s;
    int i;
    int h;
    int d;
    int m;
    int y;
    int first_last_day_of;
} timelib_rel_time;

typedef struct {
    int s;
    int i;
    int h;
    int d;
    int m;
    int y;
    int have_relative;
    timelib_rel_time relative;
} timelib_time;

static void do_adjust_for_weekday(timelib_time* time);
static void do_normalize(timelib_time* time);