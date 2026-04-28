#include <stdlib.h>
#include <string.h>

typedef long long timelib_sll;
typedef unsigned char uchar;
typedef unsigned char YYCTYPE;

#define TIMELIB_PERIOD 1
#define TIMELIB_ISO_DATE 2

typedef struct _timelib_error_container {
    int error_count;
} timelib_error_container;

typedef struct _timelib_time {
    timelib_sll y, m, d, h, i, s;
} timelib_time;

typedef struct _timelib_rel_time {
    timelib_sll y, m, d, h, i, s;
} timelib_rel_time;

typedef struct _Scanner {
    uchar *cur;
    uchar *tok;
    int len;
    int pos;
    int line;
    timelib_error_container *errors;
    timelib_time *begin;
    timelib_time *end;
    timelib_rel_time *period;
    int have_period;
    int have_date;
    int have_begin_date;
    int have_end_date;
    int have_recurrences;
    timelib_sll recurrences;
} Scanner;

#define YYDEBUG(n, c)
#define YYCURSOR s->cur
#define YYLIMIT (s->cur + s->len)
#define YYMARKER ptr
#define YYFILL(n)
#define TIMELIB_INIT
#define TIMELIB_DEINIT
#define DEBUG_OUTPUT(s)
#define add_error(s, msg) (s->errors->error_count++)

timelib_sll timelib_get_unsigned_nr(char **ptr, int max_length);
timelib_sll timelib_get_nr(char **ptr, int max_length);