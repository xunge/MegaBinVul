#include <time.h>

typedef int ngx_int_t;
typedef unsigned int ngx_uint_t;

typedef struct {
    int ngx_tm_sec;
    int ngx_tm_min;
    int ngx_tm_hour;
    int ngx_tm_mday;
    int ngx_tm_mon;
    int ngx_tm_year;
    int ngx_tm_wday;
} ngx_tm_t;

typedef int ngx_tm_sec_t;
typedef int ngx_tm_min_t;
typedef int ngx_tm_hour_t;
typedef int ngx_tm_mday_t;
typedef int ngx_tm_mon_t;
typedef int ngx_tm_year_t;
typedef int ngx_tm_wday_t;