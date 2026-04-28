#include <sys/socket.h>
#include <sys/un.h>
#include <linux/netlink.h>

struct udev;
struct udev_device;

struct udev_monitor {
    int sock;
    union {
        struct sockaddr_un sun;
        struct sockaddr_nl snl;
    };
    struct sockaddr_nl snl_peer;
    socklen_t addrlen;
    struct udev *udev;
};

void info(struct udev *udev, const char *format, ...);

ssize_t udev_device_get_properties_monitor_buf(struct udev_device *udev_device, const char **buf);