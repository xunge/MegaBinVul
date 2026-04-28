#include <stddef.h>

struct perf_event_attr {
    unsigned long sample_type;
    unsigned long read_format;
};

struct perf_event {
    struct perf_event_attr attr;
    struct perf_event *group_leader;
    size_t read_size;
    int nr_siblings;
};

size_t __perf_event_read_size(unsigned long read_format, int nr_siblings);
void __perf_event_header_size(struct perf_event *event, unsigned long sample_type);