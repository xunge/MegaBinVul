#include <stddef.h>

#define AUTH_NODE 0
#define AUTH_ENABLE_NODE 0

struct vty {
    char *buf;
    size_t cp;
    size_t length;
    int node;
};

void vty_ensure(struct vty *vty, size_t size);
void vty_write(struct vty *vty, const char *c, size_t n);