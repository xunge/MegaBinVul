#include <stddef.h>
#include <assert.h>

typedef enum {
    DBUS_VALID,
    DBUS_INVALID_TOO_MUCH_DATA
} DBusValidity;

typedef struct {
    const void *type_str;
    int type_pos;
    const unsigned char *value;
    int value_pos;
} DBusTypeReader;

typedef struct DBusString DBusString;

#define _dbus_assert(expr) assert(expr)
#define _dbus_verbose(...)
#define TRUE 1