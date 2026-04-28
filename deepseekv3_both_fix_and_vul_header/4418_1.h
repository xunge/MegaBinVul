#include <stdlib.h>
#include <pthread.h>

struct pipe_inode_info {
    struct pipe_buffer *bufs;
    unsigned long buffers;
    struct user_struct *user;
    unsigned int r_counter;
    unsigned int w_counter;
    pthread_mutex_t mutex;
    pthread_cond_t wait;
};

struct pipe_buffer {
    // 定义必要的字段
};

struct user_struct {
    // 定义必要的字段
};

#define PIPE_DEF_BUFFERS 16
#define GFP_KERNEL 0

void *kzalloc(size_t size, int flags);
void kfree(void *objp);
struct user_struct *get_current_user(void);
int too_many_pipe_buffers_hard(struct user_struct *user);
int too_many_pipe_buffers_soft(struct user_struct *user);
void account_pipe_buffers(struct pipe_inode_info *pipe, unsigned long old, unsigned long new);
void free_uid(struct user_struct *user);
void init_waitqueue_head(pthread_cond_t *cond);
void mutex_init(pthread_mutex_t *mutex);