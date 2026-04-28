#include <stdint.h>

struct perf_event_attr {
    unsigned int read_format;
};

struct perf_event {
    struct perf_event_attr attr;
    int read_size;
};

#define PERF_FORMAT_TOTAL_TIME_ENABLED  (1U << 0)
#define PERF_FORMAT_TOTAL_TIME_RUNNING  (1U << 1)
#define PERF_FORMAT_ID                  (1U << 2)
#define PERF_FORMAT_LOST                (1U << 3)
#define PERF_FORMAT_GROUP               (1U << 4)

typedef uint64_t u64;