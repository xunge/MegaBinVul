#include <stdint.h>
#include <sys/sysmacros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef char gchar;
typedef int gint;
typedef uint64_t guint64;

typedef struct _Device Device;
typedef struct _DevicePrivate DevicePrivate;

struct _DevicePrivate {
    void *d;
    void *daemon;
    gboolean device_is_linux_dmmp;
};

struct _Device {
    DevicePrivate *priv;
};

#define G_GUINT64_FORMAT "lu"

extern Device *daemon_local_find_by_dev(void *daemon, dev_t dev);
extern gchar *decode_udev_encoded_string(const gchar *str);
extern void device_set_device_file_presentation(Device *device, const gchar *path);
extern void device_set_device_is_drive(Device *device, gboolean is_drive);
extern const gchar *g_udev_device_get_property(void *d, const gchar *key);
extern const gchar* const *g_udev_device_get_property_as_strv(void *d, const gchar *key);
extern gchar *g_strdup_printf(const char *format, ...);
extern void g_free(void *ptr);
extern int g_strcmp0(const char *str1, const char *str2);