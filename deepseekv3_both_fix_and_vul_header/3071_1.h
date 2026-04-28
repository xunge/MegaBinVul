#include <stdatomic.h>
#include <stddef.h>

struct kref {
    atomic_int refcount;
};

struct vhost_net_ubuf_ref {
    struct kref kref;
    int wait;
};

void vhost_net_zerocopy_done_signal(struct kref *kref);