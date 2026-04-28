#include <string.h>

#define VTY_BUFSIZ 1024

struct vty {
    char buf[VTY_BUFSIZ];
    int cp;
    int length;
};

extern char telnet_backward_char;
extern void vty_write(struct vty *vty, const void *buf, size_t size);