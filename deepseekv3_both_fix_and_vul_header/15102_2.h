#include <stddef.h>
#include <sys/types.h>

#define UDP_HTABLE_SIZE 128
#define SEQ_START_TOKEN ((void *)1)

struct seq_file {
    void *private;
};

struct udp_iter_state {
    int bucket;
};

void *udp_get_idx(struct seq_file *seq, off_t pos);