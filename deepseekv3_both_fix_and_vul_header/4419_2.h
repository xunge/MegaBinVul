#include <stdlib.h>

struct pipe_buffer_operations {
    void (*release)(struct pipe_inode_info *, struct pipe_buffer *);
};

struct pipe_inode_info;
struct pipe_buffer {
    struct pipe_buffer_operations *ops;
};

struct pipe_inode_info {
    unsigned int buffers;
    struct pipe_buffer *bufs;
    void *tmp_page;
    void *user;
};

void account_pipe_buffers(struct pipe_inode_info *pipe, int a, int b);
void free_uid(void *user);
void __free_page(void *page);
void kfree(void *ptr);