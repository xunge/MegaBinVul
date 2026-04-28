#include <stdio.h>

#define HUB_SPEED_HIGH 1
#define HUB_SPEED_SUPER 2

#define VDEV_ST_USED 1

struct device {
    char dummy;
};

struct usb_device {
    struct device dev;
};

struct sock;

struct usbip_device {
    int status;
    int sockfd;
    struct sock *tcp_socket;
};

struct vhci_device {
    struct usbip_device ud;
    int speed;
    unsigned int devid;
    struct usb_device *udev;
};

const char *dev_name(const struct device *dev);