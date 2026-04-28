#include <sys/socket.h>
#include <linux/netlink.h>
#include <sys/un.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

struct udev;
struct udev_monitor {
    struct udev *udev;
    int sock;
    struct sockaddr_nl snl;
    struct sockaddr_un sun;
    socklen_t addrlen;
};

#define err(udev, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define dbg(udev, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)