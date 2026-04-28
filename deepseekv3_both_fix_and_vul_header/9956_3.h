#include <stdint.h>

typedef struct DBusString DBusString;
typedef struct DBusHeader DBusHeader;

struct DBusHeader {
    unsigned char byte_order;
    DBusString *data;
};

extern const DBusString _dbus_header_signature_str;

#define BYTE_ORDER_OFFSET 0

void _dbus_string_set_byte(DBusString *str, int pos, unsigned char byte);
unsigned char _dbus_string_get_byte(const DBusString *str, int pos);
void _dbus_marshal_byteswap(const DBusString *signature, int signature_start, int old_order, int new_order, DBusString *str, int start);
void _dbus_assert(int condition);