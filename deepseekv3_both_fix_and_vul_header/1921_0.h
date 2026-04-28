#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef unsigned long long usec_t;

#define USEC_PER_YEAR   ((usec_t) 31557600ULL * USEC_PER_SEC)
#define USEC_PER_MONTH  ((usec_t) 2629800ULL * USEC_PER_SEC)
#define USEC_PER_WEEK   ((usec_t) 604800ULL * USEC_PER_SEC)
#define USEC_PER_DAY    ((usec_t) 86400ULL * USEC_PER_SEC)
#define USEC_PER_HOUR   ((usec_t) 3600ULL * USEC_PER_SEC)
#define USEC_PER_MINUTE ((usec_t) 60ULL * USEC_PER_SEC)
#define USEC_PER_SEC    ((usec_t) 1000000ULL)
#define USEC_PER_MSEC   ((usec_t) 1000ULL)
#define USEC_INFINITY   ((usec_t) -1)

#define USEC_FMT "%llu"
#define PRI_USEC "llu"

#define ELEMENTSOF(array) (sizeof(array)/sizeof((array)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))