#include <sys/sysmacros.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>

#define G_GUINT64_FORMAT "lu"

typedef char gchar;
typedef unsigned int guint;
typedef uint64_t guint64;
typedef int gint;

struct udev_device {
    struct udev *udev;
    const char *syspath;
    const char *devnode;
    const char *property_value;
};

struct udev {
    int dummy;
};

static inline const char *udev_device_get_syspath(struct udev_device *udev_device) {
    return udev_device ? udev_device->syspath : NULL;
}

static inline struct udev *udev_device_get_udev(struct udev_device *udev_device) {
    return udev_device ? udev_device->udev : NULL;
}

static inline const char *udev_device_get_devnode(struct udev_device *udev_device) {
    return udev_device ? udev_device->devnode : NULL;
}

static inline const char *udev_device_get_property_value(struct udev_device *udev_device, const char *key) {
    return udev_device ? udev_device->property_value : NULL;
}

static inline struct udev_device *udev_device_new_from_syspath(struct udev *udev, const char *syspath) {
    return NULL;
}

static inline struct udev_device *udev_device_new_from_devnum(struct udev *udev, char type, dev_t devnum) {
    return NULL;
}

static inline void udev_device_unref(struct udev_device *udev_device) {
}

static inline int sysfs_get_int(const char *path, const char *attr) {
    return 0;
}

static inline uint64_t sysfs_get_uint64(const char *path, const char *attr) {
    return 0;
}

static inline char *decode_udev_encoded_string(const char *str) {
    return NULL;
}

static inline char *g_strdup(const char *str) {
    return str ? strdup(str) : NULL;
}

static inline void g_free(void *ptr) {
    free(ptr);
}

static inline int g_strcmp0(const char *str1, const char *str2) {
    if (!str1) return -(str2 != NULL);
    if (!str2) return 1;
    return strcmp(str1, str2);
}

static inline void g_printerr(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

static inline char *g_getenv(const char *name) {
    return getenv(name);
}