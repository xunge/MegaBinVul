#include <sys/types.h>
#include <stdbool.h>

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct compat_iovec {
    void *iov_base;
    size_t iov_len;
};

struct file;

struct kiocb {
    void *ki_buf;
    size_t ki_nbytes;
    struct iovec ki_inline_vec;
    struct iovec *ki_iovec;
    struct file *ki_filp;
    loff_t ki_pos;
    size_t ki_nr_segs;
    size_t ki_cur_seg;
    size_t ki_left;
};

ssize_t rw_copy_check_uvector(int type, const struct iovec *uvector,
                             unsigned long nr_segs, unsigned long fast_segs,
                             struct iovec *fast_pointer,
                             struct iovec **ret_pointer, int check_access);
ssize_t compat_rw_copy_check_uvector(int type, const struct compat_iovec *uvector,
                                    unsigned long nr_segs, unsigned long fast_segs,
                                    struct iovec *fast_pointer,
                                    struct iovec **ret_pointer, int check_access);
ssize_t rw_verify_area(int type, struct file *file, const loff_t *offset, size_t count);

#define __user