#include <stddef.h>

struct eventfd_ctx;
struct vhost_vdpa {
    struct eventfd_ctx *config_ctx;
};