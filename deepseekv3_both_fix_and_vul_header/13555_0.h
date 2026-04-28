#include <stdint.h>

typedef uint32_t dbus_uint32_t;

typedef struct DBusConnection {
    dbus_uint32_t client_serial;
} DBusConnection;