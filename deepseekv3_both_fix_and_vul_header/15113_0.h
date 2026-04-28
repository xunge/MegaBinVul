#include <sys/socket.h>
#include <sys/un.h>
#include <linux/netlink.h>

struct udev_monitor {
    int sock;
    struct sockaddr_un sun;
    struct sockaddr_nl snl;
    struct sockaddr_nl snl_peer;
    socklen_t addrlen;
    void *udev;
};

struct udev_device;

ssize_t udev_device_get_properties_monitor_buf(struct udev_device *udev_device, const char **buf);
void info(void *udev, const char *format, ...);