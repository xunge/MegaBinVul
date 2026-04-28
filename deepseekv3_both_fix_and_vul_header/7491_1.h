#include <stdlib.h>
#include <sys/types.h>

struct pipe_inode_info {
    void *user;
    int nr_accounted;
    int ring_size;
    struct pipe_buffer *bufs;
    void *tmp_page;
    void *watch_queue;
};

struct pipe_buffer {
    void *ops;
};

struct watch_queue;

#define CONFIG_WATCH_QUEUE
#define kfree free
#define __free_page(p) free(p)

void watch_queue_clear(void *queue);
void put_watch_queue(void *queue);
void account_pipe_buffers(void *user, int nr_accounted, int zero);
void free_uid(void *user);
void pipe_buf_release(struct pipe_inode_info *pipe, struct pipe_buffer *buf);