#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define YYMAXFILL 0
#define TIMELIB_UNSET -99999
#define EOI 0

typedef struct Scanner Scanner;
typedef struct timelib_time timelib_time;
typedef struct timelib_tzdb timelib_tzdb;
typedef struct timelib_error_container timelib_error_container;
typedef void (*timelib_tz_get_wrapper)(void);

struct timelib_error_container {
    int warning_count;
    char **warning_messages;
    int error_count;
    char **error_messages;
};

struct Scanner {
    char *str;
    char *cur;
    char *lim;
    timelib_time *time;
    const timelib_tzdb *tzdb;
    timelib_error_container *errors;
    int have_time;
    int have_date;
};

struct timelib_time {
    int y, m, d;
    int h, i, s;
    double f;
    int z;
    int dst;
    int is_localtime;
    int zone_type;
    int have_time;
    int have_date;
};

timelib_time* timelib_time_ctor(void);
void add_error(Scanner *in, const char *error);
void add_warning(Scanner *in, const char *warning);
int timelib_valid_time(int h, int i, int s);
int timelib_valid_date(int y, int m, int d);
void timelib_error_container_dtor(timelib_error_container *errors);
int scan(Scanner *in, ...);