#include <sys/uio.h>
#include <errno.h>

struct vrend_resource {
    struct iovec *iov;
    int num_iovs;
};

extern struct vrend_resource *vrend_resource_lookup(int res_handle, int flags);