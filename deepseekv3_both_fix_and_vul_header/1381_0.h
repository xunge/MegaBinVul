#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

struct virtio_net {
    void *mem;
    void *guest_pages;
    uint64_t log_addr;
    size_t log_size;
    struct {
        void *addr;
        size_t size;
        int fd;
    } *inflight_info;
    int slave_req_fd;
    int postcopy_ufd;
    int postcopy_listening;
};

void free_mem_region(struct virtio_net *dev);