#include <stddef.h>

struct io_ring_ctx {
    int nr_user_files;
    void *file_data;
    void *file_table;
    void *ring_sock;
};

struct file;
struct sock;
struct sk_buff;