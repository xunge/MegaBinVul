#include <stdlib.h>
#include <sys/types.h>

struct ssh;
struct monitor;
extern struct ssh *active_state;

struct monitor {
    void *m_zback;
    void *m_zlib;
};

#define MM_MEMSIZE 1024

typedef void *(*ssh_packet_comp_alloc_func)(void *, u_int);
typedef void (*ssh_packet_comp_free_func)(void *, void *);

extern struct {
    int compression;
} options;

void *xcalloc(size_t, size_t);
void monitor_openfds(struct monitor *, int);
void *mm_create(void *, size_t);
void *mm_zalloc(void *, u_int);
void mm_zfree(void *, void *);
void ssh_packet_set_compress_hooks(struct ssh *, void *,
    ssh_packet_comp_alloc_func,
    ssh_packet_comp_free_func);