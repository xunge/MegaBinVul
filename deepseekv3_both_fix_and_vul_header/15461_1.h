#include <stdbool.h>
#include <stddef.h>

struct perf_event_attr {
    unsigned long read_format;
    unsigned long sample_type;
};

struct perf_event_header {
    unsigned int type;
    unsigned int misc;
    unsigned short size;
};

struct perf_event {
    struct perf_event_attr attr;
    struct perf_event *group_leader;
    int nr_siblings;
    size_t read_size;
    size_t header_size;
    size_t id_header_size;
};

#define for_each_sibling_event(sibling, leader) \
    for ((sibling) = (leader); (sibling); (sibling) = NULL)

size_t __perf_event_read_size(unsigned long read_format, int siblings);
size_t __perf_event_header_size(struct perf_event *event, unsigned long sample_type);
void perf_event__id_header_size(struct perf_event *event);

#define PERF_SAMPLE_READ (1UL << 0)