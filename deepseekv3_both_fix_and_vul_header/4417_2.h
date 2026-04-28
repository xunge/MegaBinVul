#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)

struct file;
struct pipe_inode_info {
    unsigned long user;
    unsigned int buffers;
};

extern struct pipe_inode_info *get_pipe_info(struct file *file);
extern void __pipe_lock(struct pipe_inode_info *pipe);
extern void __pipe_unlock(struct pipe_inode_info *pipe);
extern unsigned int pipe_max_size;
extern bool too_many_pipe_buffers_hard(unsigned long user);
extern bool too_many_pipe_buffers_soft(unsigned long user);
extern long pipe_set_size(struct pipe_inode_info *pipe, unsigned int nr_pages);
extern unsigned long round_pipe_size(unsigned long size);

#define F_SETPIPE_SZ 1031
#define F_GETPIPE_SZ 1032

#define CAP_SYS_RESOURCE 24
#define CAP_SYS_ADMIN 21

static inline bool capable(int cap) { return true; }