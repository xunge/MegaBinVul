#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

struct udev_device;
struct udev_monitor {
    int sock;
    struct sockaddr_un sun;
    struct udev *udev;
};

struct ucred {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

#define UTIL_PATH_SIZE 1024
#define SCM_CREDENTIALS 2

struct udev_device *device_new(struct udev *udev);
void udev_device_set_syspath(struct udev_device *udev_device, const char *path);
void udev_device_set_subsystem(struct udev_device *udev_device, const char *subsystem);
void udev_device_set_devtype(struct udev_device *udev_device, const char *devtype);
void udev_device_set_devnode(struct udev_device *udev_device, const char *devnode);
void udev_device_add_devlink(struct udev_device *udev_device, const char *devlink);
void udev_device_set_driver(struct udev_device *udev_device, const char *driver);
void udev_device_set_action(struct udev_device *udev_device, const char *action);
void udev_device_set_devpath_old(struct udev_device *udev_device, const char *devpath_old);
void udev_device_set_physdevpath(struct udev_device *udev_device, const char *physdevpath);
void udev_device_set_seqnum(struct udev_device *udev_device, unsigned long long seqnum);
void udev_device_set_timeout(struct udev_device *udev_device, unsigned long long timeout);
void udev_device_add_property_from_string(struct udev_device *udev_device, const char *property);
void udev_device_set_devnum(struct udev_device *udev_device, dev_t devnum);
void udev_device_set_info_loaded(struct udev_device *udev_device);
void udev_device_unref(struct udev_device *udev_device);
const char *udev_get_sys_path(struct udev *udev);
void info(struct udev *udev, const char *format, ...);
size_t util_strlcpy(char *dest, const char *src, size_t size);
size_t util_strlcat(char *dest, const char *src, size_t size);