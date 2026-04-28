#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define CAP_SYS_RESOURCE 0

#define F_SETPIPE_SZ 1031  /* Set pipe size */
#define F_GETPIPE_SZ 1032  /* Get pipe size */

struct file {
    struct {
        struct {
            struct {
                struct pipe_inode_info *i_pipe;
            } *d_inode;
        } *dentry;
    } f_path;
};

struct pipe_inode_info {
    unsigned int buffers;
    struct {
        struct {
            int i_mutex;
        } *inode;
    };
};

extern unsigned long pipe_max_size;
extern unsigned int round_pipe_size(unsigned long size);
extern long pipe_set_size(struct pipe_inode_info *pipe, unsigned int nr_pages);
extern int capable(int cap);
extern void mutex_lock(int *mutex);
extern void mutex_unlock(int *mutex);