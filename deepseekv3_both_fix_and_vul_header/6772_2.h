#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/socket.h>

typedef uint32_t __u32;

struct device;
struct device_attribute;
struct socket;
struct usb_hcd;
struct platform_device;

struct vhci_device;
struct vhci_hcd;
struct vhci;

struct usbip_device {
    int sockfd;
    struct socket *tcp_socket;
    int status;
    pthread_t tcp_rx;
    pthread_t tcp_tx;
    pthread_spinlock_t lock;
};

struct vhci_device {
    __u32 devid;
    __u32 speed;
    struct usbip_device ud;
};

struct vhci_hcd {
    struct vhci *vhci;
    struct vhci_device *vdev;
};

struct vhci {
    pthread_spinlock_t lock;
    struct vhci_hcd *vhci_hcd_hs;
    struct vhci_hcd *vhci_hcd_ss;
    struct platform_device *pdev;
};

#define USB_SPEED_SUPER 3
#define VDEV_ST_NULL 0
#define VDEV_ST_NOTASSIGNED 1
#define EINVAL 22
#define EAGAIN 11
#define EBUSY 16

extern struct vhci vhcis[];
extern int port_to_pdev_nr(__u32 port);
extern int port_to_rhport(__u32 port);
extern int valid_args(int pdev_nr, int rhport, int speed);
extern void rh_port_connect(struct vhci_device *vdev, int speed);
extern const char *usb_speed_string(int speed);
extern void dev_err(struct device *dev, const char *fmt, ...);
extern void dev_info(struct device *dev, const char *fmt, ...);
extern struct socket *sockfd_lookup(int fd, int *err);
extern void sockfd_put(struct socket *sock);
extern struct usb_hcd *platform_get_drvdata(struct platform_device *pdev);
extern struct vhci_hcd *hcd_to_vhci_hcd(struct usb_hcd *hcd);
extern void usbip_dbg_vhci_sysfs(const char *fmt, ...);
extern void *vhci_rx_loop(void *arg);
extern void *vhci_tx_loop(void *arg);