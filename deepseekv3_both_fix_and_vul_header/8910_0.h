#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define VTY_BUFSIZ 1024

struct vty {
    char buf[VTY_BUFSIZ];
    size_t cp;
    size_t length;
};

void vty_write(struct vty *vty, char *str, size_t nwrite);