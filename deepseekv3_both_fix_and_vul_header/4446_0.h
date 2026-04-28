#include <sys/types.h>
#include <unistd.h>

struct file;
struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct kiocb {
    loff_t ki_pos;
    size_t ki_left;
    void *ki_buf;
    struct iovec *ki_iovec;
    struct iovec ki_inline_vec;
    unsigned short ki_nr_segs;
    unsigned short ki_cur_seg;
};

ssize_t rw_verify_area(int type, struct file *file, loff_t *pos, size_t count);