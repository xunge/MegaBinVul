#include <sys/socket.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

struct socket {
    void *sk;
    struct {
        int f_flags;
    } *file;
};

struct compat_msghdr {
    void *msg_name;
    int msg_namelen;
    struct iovec *msg_iov;
    int msg_iovlen;
    void *msg_control;
    int msg_controllen;
    unsigned int msg_flags;
};

struct used_address {
    unsigned int name_len;
    void *name;
};

#define UIO_FASTIOV 8
#define GFP_KERNEL 0
#define VERIFY_READ 0
#define MSG_CMSG_COMPAT 0x80000000

#define __user
#define __kernel_size_t size_t
#define __force